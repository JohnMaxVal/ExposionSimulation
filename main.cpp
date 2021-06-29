#include <iostream>
#include "Screen.h"

using namespace std;
using namespace explosion;

int main(int argc, char *argv[]) {

    Screen screen;

    if(!screen.init()) {
        cout << "SDl initialization failed." << endl;
        return 0;
    }

    while(true) {

        // Draw particles
        for(int y = 0; y < 600; y++) {
            for(int x = 0; x < 800; x++) {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }

        screen.setPixel(400, 300, 0xff, 0xff, 0xff);

        screen.update();

        if(!screen.processEvents()) {
            break;
        }
    }

    screen.close();

    return 0;
}