#include <iostream>
#include "cgame.hpp"


int main(){
	std::unique_ptr<CGameObj>text = std::make_unique<CGameObj>();
	std::unique_ptr<CGameObj>text2 = std::make_unique<CGameObj>();	
	if((CGame::getGameInst()->getGame()->quit = !CGame::getGameInst()->initMainWindow(
		SDL_INIT_EVERYTHING,
		"Lolkek",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		500,
		500,
		SDL_WINDOW_SHOWN
	))) return -1;
	CGame::getGameInst()->getGame()->quit = !text->loadTexture(CGame::getGameInst()->getGame()->getRenderer(),"/home/sergo/Tutorials/SDL2/TwinklebearDev-Lessons/res/Lesson3/image.png");
	CGame::getGameInst()->getGame()->quit = !text2->loadTexture(CGame::getGameInst()->getGame()->getRenderer(),"/home/sergo/Tutorials/SDL2/TwinklebearDev-Lessons/res/Lesson3/image.png");
	CGame::getGameInst()->addObject("Text",std::move(text));
	text2->setPos(100,0);
	CGame::getGameInst()->addObject("Text2",std::move(text2));
	CGame::getGameInst()->gameProcces();
	return 0;
}