#include "framework.hpp"
#include "logger/logger.hpp"
#include "event/event_manager.hpp"

int main(){
    bool isRunning = false;

    Logger::getLogger()->setLogLevel(LogLevel::DEBUG);

    isRunning = AirHockey::init();

    if (isRunning) {
        EventManager::getManager()->run();
    }

    while (isRunning) {
        AirHockey::handleEvent();

        isRunning = AirHockey::update();
    }

    AirHockey::close();

    return 0;
}

