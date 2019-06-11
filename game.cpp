#include <iostream>
#include "cwindow.hpp"

int main(){
	CWindow* gameWnd = new CWindow();
	if((gameWnd->quit = !gameWnd->init(
		SDL_INIT_EVERYTHING,
		"Lolkek",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		500,
		500,
		SDL_WINDOW_SHOWN
	))) return -1;
	
	while (!gameWnd->quit)
	{
		gameWnd->handleEvent();
		SDL_RenderClear(gameWnd->getRenderer());
		SDL_RenderPresent(gameWnd->getRenderer());
	}
	delete gameWnd;
	return 0;
}