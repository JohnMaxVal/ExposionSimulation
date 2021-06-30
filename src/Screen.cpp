#include <cstring>
#include "Screen.h"

using namespace std;

namespace explosion {

Screen::Screen():
    m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buf1(NULL), m_buf2(NULL) {

}

bool Screen::init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    m_window = SDL_CreateWindow("Explosion", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if(m_window == NULL) {
        SDL_Quit();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(
        m_renderer, 
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STATIC,
        SCREEN_WIDTH,
        SCREEN_HEIGHT);

    if(m_renderer == NULL) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    if(m_texture == NULL) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_buf1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    m_buf2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    memset(m_buf1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    memset(m_buf2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    return true;
}

bool Screen::processEvents() {
    // separate function - processInput();
    SDL_Event event;
    SDL_PollEvent(&event);

    if(event.type == SDL_QUIT) {
        return false;
    }
    return true;
}

void Screen::update() {
    SDL_UpdateTexture(m_texture, NULL, m_buf1, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

    if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }

    Uint32 color = 0;

    color |= red;
    color = (color << 8) | green;
    color = (color << 8) | blue;
    color = (color << 8) | 0xff;

    m_buf1[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::close() {
    delete[] m_buf1;
    delete[] m_buf2;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Screen::boxBlur() {
    Uint32 *tmp = m_buf1;
    m_buf1 = m_buf2;
    m_buf2 = tmp;

    for(int y = 0; y < SCREEN_HEIGHT; y++) {
        for(int x = 0; x < SCREEN_WIDTH; x++) {
            
            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;

            for(int row = -1; row <= 1; row++) {
                for(int col = -1; col <= 1; col++) {
                    int curr_x = x + col;
                    int curr_y = y + row;

                    if(curr_x >= 0 && curr_x < SCREEN_WIDTH && curr_y >= 0 && curr_y < SCREEN_HEIGHT) {
                        // Get color value of the pixel
                        Uint32 color = m_buf2[curr_y * SCREEN_WIDTH + curr_x];

                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;

                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                    }
                }
            }

            Uint8 red = redTotal / 9;
            Uint8 green = greenTotal / 9;
            Uint8 blue = blueTotal / 9;

            setPixel(x, y, red, green, blue);
        }
    }
}

}