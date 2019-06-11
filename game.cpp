#include <iostream>
#include "cgame.hpp"


int main(){
	std::unique_ptr<CGameObj>text = std::make_unique<CGameObj>();
	std::unique_ptr<CGameObj>arrow = std::make_unique<CGameObj>();	
	CGame::getGameInst()->initMainWindow(
		SDL_INIT_EVERYTHING,
		"Lolkek",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		500,
		500,
		SDL_WINDOW_SHOWN);
	text->loadTexture(CGame::getGameInst()->getGameWindow()->getRenderer(),"/home/sergo/Tutorials/SDL2/TwinklebearDev-Lessons/res/Lesson3/image.png");
	arrow->loadTexture(CGame::getGameInst()->getGameWindow()->getRenderer(),"/home/sergo/Airhockey/source/pictures/arrow.png");
	arrow->setSize(100,60);
	CGame::getGameInst()->addObject("Text",std::move(text));
	arrow->setPos(0,0);
	CGame::getGameInst()->addObject("arrow",std::move(arrow));
	CGame::getGameInst()->gameProcess();
	return 0;
}