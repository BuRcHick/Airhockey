#include "cgameobj.hpp"

/**
 * Default game object constructor
 */
CGameObj::CGameObj(){
	texture = nullptr;
	posX = posY = width = heigth = 0;
}

/**
 * Copy constructor
 */
CGameObj::CGameObj(CGameObj&& obj){
	texture = obj.texture;
	posX = obj.posX;
	posY = obj.posY;
	width = obj.width;
	heigth = obj.heigth;
	obj.texture = nullptr;
}

CGameObj::~CGameObj(){
	SDL_DestroyTexture(texture);
	printf("GameObject deleted successfuly!\n");
}

/**
 * Texture loading
 */
bool CGameObj::loadTexture(SDL_Renderer* rndr, const std::string& path){
	if(!(texture = IMG_LoadTexture(rndr,path.c_str()))){
		perror("Error! The texture loading filed...");
		return false;
	}
	SDL_QueryTexture(texture,NULL,NULL,&width,&heigth);
	return true;
}

/**
 * Rendering the texture
 */
void CGameObj::renderTexture(SDL_Renderer* rndr){
	SDL_Rect rect;
	rect.x = posX;
	rect.y = posY;
	rect.w = width;
	rect.h = heigth;
	SDL_RenderCopy(rndr,texture,NULL,&rect);
}

/**
 * Running the object event function
 */
void CGameObj::runEventFunc(const UserEvents eventType){
	if(!ifEventExcist(eventType)){
		perror("Error! Event doesn't excist...");
		return;
	}
	events.find(eventType)->second->execFunc();
}

/**
 * Add event to object
 */
bool CGameObj::addEvent(const UserEvents eventType, std::shared_ptr<CEvent> event){
	if(ifEventExcist(eventType)){
		perror("Error! Event already excist...");
		return false;
	}
	events[eventType] = event;
	return true;
}

bool CGameObj::addEvent(const UserEvents eventType, const std::function<void()>& eventFunc){
	if(ifEventExcist(eventType)){
		perror("Error! Event already excist...");
		return false;
	}
	events[eventType] = std::make_shared<CEvent>(eventFunc);
	return true;
}

/**
 * Remove event
 */
bool CGameObj::removeEvent(const UserEvents eventType){
	if(!ifEventExcist(eventType)){
		perror("Error! Event doesn't excist...");
		return false;
	}
	events.erase(eventType);
	return true;
}

void CGameObj::setTexture(SDL_Texture* _texture){
	if(!_texture){
		perror("Error! Texture settings nulptr...");
		return;
	}
	if(texture){
		SDL_DestroyTexture(texture);
	}
	texture = _texture;
}