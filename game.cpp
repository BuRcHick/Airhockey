#include <iostream>
#include "cgame.hpp"
#define WIDTH	700
#define HEIGHT	900
int main(){
	auto mainMenu = std::make_unique<CPreset>();
	auto background = std::make_shared<CGameObj>();
	CGame::getGameInst()->initMainWindow(
		SDL_INIT_EVERYTHING,
		"Lolkek",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH,
		HEIGHT,
		SDL_WINDOW_SHOWN);
	SDL_Renderer* rndr = CGame::getGameInst()->getGameWindow()->getRenderer();
	background->loadTexture(rndr,PICTURES_FOLDER + (std::string)"/background.png");	
	mainMenu->createPreset([&](){
		auto startText = std::make_shared<CText>();
		auto quitText = std::make_shared<CText>();
		auto arrowText = std::make_shared<CText>();
		SDL_Color color = { 0, 0, 0, 255 };
		startText->createText(
			"Start",
			FONTS_FOLDER + (std::string)"/sample.ttf",
			color,
			80,
			rndr);
		quitText->createText(
			"Quit",
			FONTS_FOLDER + (std::string)"/sample.ttf",
			color,
			80,
			rndr);
		arrowText->createText(
			"->",
			FONTS_FOLDER + (std::string)"/sample.ttf",
			color,
			80,
			rndr);
		int iW, iH;
		SDL_QueryTexture(startText->getTexture(), NULL, NULL, &iW, &iH);
		int x = WIDTH / 2 - iW / 2;
		int y = HEIGHT / 2 - iH / 2;
		startText->setPos(x,y - iH);
		quitText->setPos(x,y);
		arrowText->setPos(x,y-iH);
		SDL_QueryTexture(arrowText->getTexture(), NULL, NULL, &iW, &iH);
		arrowText->setPos(arrowText->getPos().first - iW, arrowText->getPos().second);
		arrowText->addEvent(UserEvents::ObjectMoveDown,[&](){
			if(arrowText->getPos().second < quitText->getPos().second){
				arrowText->setPos(arrowText->getPos().first,quitText->getPos().second);
			}
		});
		arrowText->addEvent(UserEvents::ObjectMoveUp,[&](){
			if(arrowText->getPos().second > startText->getPos().second){
				arrowText->setPos(arrowText->getPos().first,startText->getPos().second);
			}
		});
		arrowText->addEvent(UserEvents::PressEnter,[&](){
			if(arrowText->getPos().second == quitText->getPos().second){
				CGame::getGameInst()->changeGameProcess(false);
			}
		});
		CGame::getGameInst()->setGameEventsHendlers([&](){
			SDL_Event event;
			SDL_PollEvent(&event);
			switch (event.type)
			{
			case SDL_QUIT:
				CGame::getGameInst()->changeGameProcess(false);
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_RIGHT:
					break;
				case SDLK_LEFT:
					break;
				case SDLK_UP:
					CEventManager::getManager()->trigerEvent(UserEvents::ObjectMoveUp,"arrowText");					break;
				case SDLK_DOWN:
					CEventManager::getManager()->trigerEvent(UserEvents::ObjectMoveDown,"arrowText");
					break;
				case SDLK_RETURN:
					CEventManager::getManager()->trigerEvent(UserEvents::PressEnter,"arrowText");
					break;
				default:
					break;
				}
				break;
			case SDL_USEREVENT:
				CGame::getGameInst()->getObj((const char*)event.user.data1)->runEventFunc((UserEvents)event.user.code);
				break;
			default:
				break;
			}
		});
		CGame::getGameInst()->addObject("startText",startText);
		CGame::getGameInst()->addObject("qutText",quitText);
		CGame::getGameInst()->addObject("arrowText",arrowText);
		CGame::getGameInst()->addObject("background",background);
		CGame::getGameInst()->gameProcess();
	});
	mainMenu->runPreset();
	CGame::getGameInst()->ereseGameObjects();
	if(!CGame::getGameInst()->ifRunning()){
		return 0;
	}
	auto gameProc = std::make_unique<CPreset>();
	gameProc->createPreset([&](){
		auto ball = std::make_shared<CGameObj>();
		ball->loadTexture(rndr,PICTURES_FOLDER + (std::string)"/ball.png");
		auto player1 = std::make_shared<CGameObj>();
		player1->loadTexture(rndr,PICTURES_FOLDER + (std::string)"/red.png");		
		auto player2 = std::make_shared<CGameObj>();
		player2->loadTexture(rndr,PICTURES_FOLDER + (std::string)"/red2.png");
		ball->setSize(50,50);
		player1->setSize(60,60);
		player2->setSize(60,60);
		int x = WIDTH / 2 - ball->getSize().first / 2;
		int y = HEIGHT / 2 - ball->getSize().second / 2;
		ball->setPos(x,y);
		x = WIDTH / 2 - player1->getSize().first / 2;
		y = player1->getSize().second / 2;
		player1->setPos(x, y);
		y = HEIGHT - player2->getSize().second*2;
		player2->setPos(x,y);
		CGame::getGameInst()->addObject("ball",ball);
		CGame::getGameInst()->addObject("player1",player1);
		CGame::getGameInst()->addObject("player2",player2);
		CGame::getGameInst()->addObject("background",background);
		CGame::getGameInst()->setGameEventsHendlers([&](){
			SDL_Event event;
			SDL_PollEvent(&event);
			switch (event.type)
			{
			case SDL_QUIT:
				CGame::getGameInst()->changeGameProcess(false);
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_RIGHT:
					break;
				case SDLK_LEFT:
					break;
				case SDLK_UP:
				case SDLK_DOWN:
					break;
				case SDLK_RETURN:
					break;
				default:
					break;
				}
				break;
			case SDL_USEREVENT:
				CGame::getGameInst()->getObj((const char*)event.user.data1)->runEventFunc((UserEvents)event.user.code);
				break;
			default:
				break;
			}
		});
		CGame::getGameInst()->gameProcess();
	});
	CGame::getGameInst()->changeGameProcess(true);
	gameProc->runPreset();
	return 0;
}