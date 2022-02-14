#include "framework.hpp"
#include "logger/logger.hpp"
#include "event/event_manager.hpp"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main(){
    bool isRunning = false;

    Logger::getLogger()->setLogLevel(LogLevel::DEBUG);

    isRunning = AirHockey::init();


    if (isRunning) {
        EventManager::getManager()->run();
    }

    auto previousTime = std::chrono::high_resolution_clock::now();
    while (isRunning) {
        auto currentTime = previousTime;
        std::chrono::duration<float> duration = currentTime - previousTime;
        AirHockey::handleEvent();

        if (duration.count() < 0.15f) {
            isRunning = AirHockey::update(0.15f);
        } else {
            isRunning = AirHockey::update(duration.count());
        }
        std::this_thread::sleep_for(15ms);
        previousTime = std::chrono::high_resolution_clock::now();
    }

    AirHockey::close();

    return 0;
}

