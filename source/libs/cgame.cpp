#include "cgame.hpp"
#include <cstdio>
#define FPS 120
const int frameDelay = 1000/FPS;

CGame* CGame::gameInst = nullptr;

CGame::CGame(/* args */)
{
    running = false;
    mainWnd = nullptr;
}

CGame::~CGame()
{
    printf("End Game\n");
    objects.clear();
    delete mainWnd;
}

/**
 * Window initialization
 */
void CGame::init(int initF)
{
    if (SDL_Init(initF) < 0) {
        perror("Failed to init SDL");
        return;
    }

    if(!mainWnd){
        mainWnd = Window::create("AirHockey");
    }
}
/**
 * Acces for the game
 */
CGame* CGame::getGameInst(){
    if(!gameInst){
        gameInst = new CGame();
        struct gameEraser
        {
            ~gameEraser(){delete gameInst; }
        };
        static gameEraser eraser;
    }
    return gameInst;
}

/**
 * Add game object to main window
 */
bool CGame::addObject(const std::string& key, std::shared_ptr<CGameObj> obj){
    if(objects.find(key) != objects.end()){
        perror("Error! Add object to game... Same obj excist!");
        return false;
    }
    objects[key] = obj;
    return true;
}

/**
 * Removing object from game
 */
void CGame::removeObject(const std::string& key){
    if(objects.find(key) == objects.end()){
        perror("Error! Removing the object failed...");
        return;
    }
    objects.erase(key);
}

/**
 * Draw the game
 */
void CGame::draw(){
    SDL_RenderClear(mainWnd->getRenderer());
    for(auto& object:objects){
        if(object.second)
            object.second->renderTexture(mainWnd->getRenderer());
    }
    SDL_RenderPresent(mainWnd->getRenderer());
}

/**
 * main game proccess
 */
void CGame::gameProcess(){
    int ticks = 0;
    int time = 0;
    while (running){
        ticks = SDL_GetTicks();
        handleGameEvents();
        draw();
        time = SDL_GetTicks() - ticks;
        if(frameDelay > time){
            SDL_Delay(frameDelay - time);
        }
    }
    printf("EndProcces\n");
}

/**
 * Moving some game object
 */
void CGame::moveObject(const std::string& key, int x, int y){
    if(objects.find(key) == objects.end()){
        perror("Error! Moving object: object doesn't excist...");
        return;
    }
    std::pair<int,int>position = objects.find(key)->second->getPos();
    objects.find(key)->second->setPos(position.first + x,position.second + y);
}

/**
 * Handling the games events
 */
void CGame::setGameEventsHendlers(const std::function<void()>& events){
    handleGameEvents = events;
}
