#include "cgame.hpp"
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
void CGame::initMainWindow(
	u_int32_t initF, 
	const std::string& title, 
	int x, int y, int w, int h, 
	u_int32_t wndFlags){
	if(!mainWnd){
		mainWnd = new CWindow();
	}
	running = mainWnd->init(initF,title,x,y,w,h,wndFlags);
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
bool CGame::addObject(const std::string& key, std::unique_ptr<CGameObj> obj){
	if(objects.find(key) != objects.end()){
		perror("Error! Add object to game... Same obj excist!");
		return false;
	}
	objects[key] = std::move(obj);
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
	unsigned int ticks = SDL_GetTicks();
	while (running){
		handleGameEvents();
		draw();
		if((1000/FPS) > SDL_GetTicks() - ticks){
			SDL_Delay(1000/FPS - (SDL_GetTicks() - ticks));
		}
	}
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
void CGame::handleGameEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		running = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_RIGHT:
			break;
		case SDLK_LEFT:
			break;
		case SDLK_UP:
			break;
		case SDLK_DOWN:
			break;
		default:
			break;
		}
		break;
	case SDL_USEREVENT:
		break;
	default:
		break;
	}
}