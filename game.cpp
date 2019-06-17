#include <iostream>
#include "cgame.hpp"

int main(){
	auto ball = std::make_shared<CGameObj>();
	auto player1 = std::make_shared<CGameObj>();
	auto player2 = std::make_shared<CGameObj>();
	auto mainMenu = std::make_unique<CPreset>();
	CGame::getGameInst()->initMainWindow(
		SDL_INIT_EVERYTHING,
		"Lolkek",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		500,
		500,
		SDL_WINDOW_SHOWN);
	SDL_Renderer* rndr = CGame::getGameInst()->getGameWindow()->getRenderer();
	mainMenu->createPreset([&](){
		ball->loadTexture(rndr,PICTURES_FOLDER + (std::string)"/ball.png");
		ball->setSize(100,100);
		ball->setPos(0,0);
		player1->loadTexture(rndr,PICTURES_FOLDER + (std::string)"/red.png");
		player1->setSize(50,50);
		player1->setPos(0,ball->getSize().second);
		player2->loadTexture(rndr,PICTURES_FOLDER + (std::string)"/red2.png");
		player2->setSize(50,50);
		player2->setPos(0,player1->getSize().second + player1->getPos().second);
		CGame::getGameInst()->addObject("ball",ball);
		CGame::getGameInst()->addObject("player1",player1);
		CGame::getGameInst()->addObject("player2",player2);
		CGame::getGameInst()->gameProcess();
	});
	CGame::getGameInst()->addPreset("MainMenu",std::move(mainMenu));
	CGame::getGameInst()->runPreset("MainMenu");
	return 0;
}