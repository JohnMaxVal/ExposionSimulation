#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SDL.h>

namespace explosion {

class Screen {
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    Uint32 *m_buf1;
    Uint32 *m_buf2;

public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
    Screen();

    bool init();
    bool processEvents();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void close();
    void boxBlur();
};

}

#endif