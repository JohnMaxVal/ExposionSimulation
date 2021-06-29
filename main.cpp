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
        // Update particles
        // Draw particles
        // Chech for events
        if(!screen.processEvents()) {
            break;
        }
    }

    screen.close();

    return 0;
}