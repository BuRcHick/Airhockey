#ifndef EVENTS
#define EVENTS
#include "SDL2/SDL.h"
#include <stdio.h>
#include <memory>
#include <unordered_map>
#include <string>
#include "cevent.hpp"
class CEventManager
{
private:
	SDL_Event event;
	static CEventManager* managerInstance;
	CEventManager(/* args */);
	~CEventManager();
public:
	static CEventManager* getManager();
	void handleEvents();
	void trigerEvent(const UserEvents, const char[10]);
};

#endif //EVENTS