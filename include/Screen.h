#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SDL.h>

namespace explosion {

class Screen {
private:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    uint32_t *m_buf;

public:
    Screen();

    bool init();
    bool processEvents();
    void close();
};

}

#endif