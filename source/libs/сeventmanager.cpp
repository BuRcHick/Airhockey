#include "сeventmanager.hpp"
CEventManager* CEventManager::managerInstance;

CEventManager::CEventManager(){
	printf("Creating manager!\n");
}

CEventManager::~CEventManager(){
	printf("Deleting manager!\n");
}

/**
 * Returns pointer to manager
 */
CEventManager* CEventManager::getManager(){
	if(!managerInstance){
		managerInstance = new CEventManager();
		struct Eraser
		{
			~Eraser(){delete managerInstance; }
		};
		static Eraser eraser;
	}
	return managerInstance;
}

void CEventManager::handleEvents(){
}

void CEventManager::trigerEvent(const UserEvents eventType, const char obj[10]){
	event.type = SDL_USEREVENT;
	event.user.code = (int)eventType;
	event.user.data1 = (void*)obj;
	if(!SDL_PushEvent(&event)){
		printf("Error! Event triger : %s\n",SDL_GetError());
	}
}