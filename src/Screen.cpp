#include <cstring>
#include "Screen.h"

using namespace std;

namespace explosion {

Screen::Screen():
    m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buf(NULL) {

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

    Uint32 *buf = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    memset(buf, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    SDL_UpdateTexture(m_texture, NULL, buf, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);

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

void Screen::close() {
    delete[] m_buf;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

}