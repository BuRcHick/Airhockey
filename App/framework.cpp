#include "SDL2/SDL.h"
#include "framework.hpp"
#include "texture/texture_manager.hpp"
#include "game_objects/hockey_striker.hpp"
#include "game_objects/hockey_puck.hpp"
#include "event/event_manager.hpp"
#include "logger/logger.hpp"
#include "xml/xml_loader.hpp"

#include <random>
#include <ctime>

Game* Game::m_game = nullptr;
bool isRunning = false;

Game::Game()
    :m_buttomBorder(0, 0, 0, 0),
    m_topBorder(0, 0, 0, 0),
    m_leftBorder(0, 0, 0, 0),
    m_rightBorder(0, 0, 0, 0),
    m_leftGate(0, 0, 0, 0),
    m_rightGate(0, 0, 0, 0)
{
    m_window = Window::create("Big Dick Game");
    m_window->resize(WIDTH, HEIGHT);

    m_parser = new ConfigParser();
}

Game::~Game()
{
    delete m_parser;
}

Game* Game::getGame()
{
    if (nullptr == m_game) {
        m_game = new Game();
    }

    return m_game;
}

bool Game::init()
{
    bool result = true;
    int width = 0;
    int height = 0;

    result = m_parser->load(CONFIG_FOLDER "/config.xml");
    result &= m_parser->parse();
    if (result != true) {
        LOG_ERROR("Failed to parse config");

        return false;
    }

    m_config = dynamic_cast<ConfigParser*>(m_parser)->getConfig();

    m_striker_1 = std::make_shared<HockeyStriker>();
    m_striker_2 = std::make_shared<HockeyStriker>();
    m_puck = std::make_shared<HockeyPuck>();

    m_striker_1->resize(m_config.scene.hockeyStriker.width,
                        m_config.scene.hockeyStriker.height);
    m_striker_1->setPosition(Point2D(10, 0));

    m_puck->resize(m_config.scene.hockeyPuck.width,
                   m_config.scene.hockeyPuck.height);

    width = m_config.global.width / 2 - m_config.scene.hockeyPuck.width / 2;
    height = m_config.global.height / 2 - m_config.scene.hockeyPuck.height / 2;
    m_puck->setPosition(Point2D((float) width, (float) height));

    height = m_config.global.height - m_config.scene.bottomBorder.height;
    m_buttomBorder.move(0, (float) height);
    m_buttomBorder.resize(m_config.scene.bottomBorder.width,
                          m_config.scene.bottomBorder.height);

    m_topBorder.move(0, 0);
    m_topBorder.resize(m_config.scene.topBorder.width,
                       m_config.scene.topBorder.height);

    m_leftBorder.move(0, 0);
    m_leftBorder.resize(m_config.scene.leftBorder.width,
                        m_config.scene.leftBorder.height);

    width = m_config.global.width - m_config.scene.rightBorder.width;
    m_rightBorder.move((float) width, 0);
    m_rightBorder.resize(m_config.scene.rightBorder.width,
                         m_config.scene.rightBorder.height);

    m_window->resize(m_config.global.width, m_config.global.height);

    EventManager::getManager()->subscribeOnEvent(
            std::make_pair(EventType::SDL_Event, SDL_MOUSEMOTION),
            m_striker_1);
    EventManager::getManager()->subscribeOnEvent(
            std::make_pair(EventType::GameEvent, GameEventType::Tick),
            m_puck);

    std::srand(std::time(nullptr));

    return true;
}

void Game::draw()
{
    SDL_Renderer* renderer = m_window->getRenderer();
    TextureManager* texture_manager = TextureManager::getManager();

    SDL_RenderClear(renderer);

    texture_manager->drawTextureByID((int)TexturesID::HockeyBackground, 0, 0, WIDTH, HEIGHT);
    m_striker_1->draw();

    SDL_RenderPresent(renderer);

}

bool AirHockey::init()
{
    Game* game = Game::getGame();
    TextureManager* manager = TextureManager::getManager();

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    manager->setRenderer(game->getWindow()->getRenderer());

    isRunning = true;

    isRunning &= manager->addTextureByPath((int)TexturesID::HockeyBackground, ASSETS_FOLDER "/BackGround.png");
    isRunning &= manager->addTextureByPath((int)TexturesID::HockeyStriker, ASSETS_FOLDER "/Striker.png");
    isRunning &= manager->addTextureByPath((int)TexturesID::HockeyPuck, ASSETS_FOLDER "/Puck.png");

    isRunning &= game->init();

    return isRunning;
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

    game->draw();

    return isRunning;
}

void AirHockey::close()
{
    EventManager::getManager()->stop();
    SDL_Quit();
}
