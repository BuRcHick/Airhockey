#include <iostream>
#include "cwindow.hpp"
#include "cgameobj.hpp"

int main(){
	CWindow* gameWnd = new CWindow();
	CGameObj* text = new CGameObj();
	if((gameWnd->quit = !gameWnd->init(
		SDL_INIT_EVERYTHING,
		"Lolkek",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		500,
		500,
		SDL_WINDOW_SHOWN
	))) return -1;
	gameWnd->quit = !text->loadTexture(gameWnd->getRenderer(),"/home/sergo/Tutorials/SDL2/TwinklebearDev-Lessons/res/Lesson3/image.png");
	while (!gameWnd->quit)
	{
		gameWnd->handleEvent();
		SDL_RenderClear(gameWnd->getRenderer());
		text->renderTexture(gameWnd->getRenderer());
		SDL_RenderPresent(gameWnd->getRenderer());
	}
	delete text;
	delete gameWnd;
	return 0;
}