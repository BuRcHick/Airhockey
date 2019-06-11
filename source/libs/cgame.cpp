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
bool CGame::initMainWindow(
	u_int32_t initF, 
	const std::string& title, 
	int x, int y, int w, int h, 
	u_int32_t wndFlags){
	if(!mainWnd){
		mainWnd = new CWindow();
	}
	return mainWnd->init(initF,title,x,y,w,h,wndFlags);
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

void CGame::gameProcces(){
	while (!mainWnd->quit){
		mainWnd->handleEvent();
		draw();
	}
}