#include "framework.hpp"

#define WIDTH   700
#define HEIGHT  900

int main(){
    bool isRunning = false;

    isRunning = AirHockey::init();

    while (isRunning) {
        AirHockey::handleEvent();

        isRunning = AirHockey::update();
    }

    AirHockey::close();

    return 0;
}

