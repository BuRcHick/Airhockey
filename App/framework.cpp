#include "SDL2/SDL.h"

#include "framework.hpp"
#include "texture/texture_manager.hpp"
#include "game_objects/hockey_striker.hpp"

Game* Game::m_game = nullptr;

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

    return true;
}

void AirHockey::handleEvent()
{
    /* TODO */
}

bool AirHockey::update()
{
    /* TODO */
    return false;
}

void AirHockey::close()
{
    SDL_Quit();
}
