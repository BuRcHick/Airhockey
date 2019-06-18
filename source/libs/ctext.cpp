#include "ctext.hpp"
CText::CText(/* args */)
{
	if (TTF_Init() != 0){
		perror("TTF_Init");
	}
}

CText::~CText()
{
	printf("Remove text\n");
}

bool CText::createText(
	const std::string& text,
	const std::string& fontFile, 
	SDL_Color color,
	int fontSize, 
	SDL_Renderer* rndr){
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr){
		printf("Error! %s\n",TTF_GetError());
		//perror("Error! Text creating");
		return false;
	}
	SDL_Surface *surf = TTF_RenderText_Blended(font, text.c_str(), color);
	if (surf == nullptr){
		TTF_CloseFont(font);
		perror("Error! Text creating");
		return false;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(rndr, surf);
	if (texture == nullptr){
		perror("Error! Text creating");
	}
	setTexture(texture);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return true;
}

void CText::renderTexture(SDL_Renderer* rndr){
	SDL_Rect dst;
	SDL_QueryTexture(getTexture(), NULL, NULL, &dst.w, &dst.h);
	dst.x = getPos().first;
	dst.y = getPos().second;
	SDL_RenderCopy(rndr,getTexture(),NULL,&dst);
}