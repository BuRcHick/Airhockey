#include "SDL2/SDL.h"

#include "framework.hpp"
#include "texture/texture_manager.hpp"
#include "game_objects/hockey_striker.hpp"
#include "event/event_manager.hpp"

Game* Game::m_game = nullptr;
bool isRunning = false;

Game::Game()
{
    m_window = Window::create("Big Dick Game");
}

Game* Game::getGame()
{
    if (nullptr == m_game) {
        m_game = new Game();
    }

    return m_game;
}

bool AirHockey::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    isRunning = true;

    return true;
}

void AirHockey::handleEvent()
{
    SDL_Event sdl_event;
    std::unique_ptr<Event> event;

    while (SDL_PollEvent(&sdl_event)) {
        switch (sdl_event.type) {
            case SDL_QUIT:
                AirHockey::close();

                isRunning = false;

                break;
            default:
                event = std::make_unique<Event>();
                event->type = EventType::SDL_Event;
                event->data.sdl_event = sdl_event;

                EventManager::pushEvent(std::move(event));

                break;
        }
    }
}

bool AirHockey::update()
{
    Game* game = Game::getGame();

    game->m_window->show();
    game->m_window->update();

    return isRunning;
}

void AirHockey::close()
{
    EventManager::getManager()->stop();
    SDL_Quit();
}
