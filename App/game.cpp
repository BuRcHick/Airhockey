#include "framework.hpp"

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

