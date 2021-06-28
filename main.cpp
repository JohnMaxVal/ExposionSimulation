#include <SDL.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREE_HEIGHT = 600;

bool isRunning = true;

int main(int argc, char *argv[]) {

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed" << endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Explosion", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREE_HEIGHT,
        SDL_WINDOW_SHOWN);

    if(window == NULL) {
        cout << "Could not create window: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    SDL_Event event;

    while(isRunning) {
        // Update particles
        // Draw particles
        // Chech for events

        // separate function - processInput();
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
        }
    }

    SDL_DestroyWindow(window);
    cout << "Windows destroyed" << endl;
    SDL_Quit();

    return 0;
}