#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace explosion;

int main(int argc, char *argv[]) {

    srand(time(NULL));

    Screen screen;

    if(!screen.init()) {
        cout << "SDl initialization failed." << endl;
        return 0;
    }

    Swarm swarm;

    while(true) {

        int elapsed = SDL_GetTicks();
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.001)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.003)) * 128);

        const Particle * const pParticles = swarm.getParticles();
        for(int i = 0; i < Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];

            int p_X = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int p_Y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

            screen.setPixel(p_X, p_Y, red, green, blue);
        }

        // Draw the screen
        screen.update();

        if(!screen.processEvents()) {
            break;
        }
    }

    screen.close();

    return 0;
}