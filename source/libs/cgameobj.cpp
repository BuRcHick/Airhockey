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