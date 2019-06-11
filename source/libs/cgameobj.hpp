#ifndef CGAMEOBJ
#define CGAMEOBJ
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <stdio.h>
class CGameObj
{
private:
	SDL_Texture* texture;
	int posX, posY, width, heigth;
public:
	CGameObj();
	CGameObj(const CGameObj&) = delete;
	CGameObj& operator = (const CGameObj&) = delete;
	CGameObj(CGameObj&&);
	~CGameObj();

	bool loadTexture(SDL_Renderer*,const std::string& path);
	void renderTexture(SDL_Renderer*);
	void setPos(int x, int y){posX = x; posY = y;};
	void setSize(unsigned int w, unsigned int h){width = w; heigth = h;}
	const std::pair<int, int> getPos(){return std::make_pair(posX,posY);}
	const std::pair<unsigned int, unsigned int> getSize(){return std::make_pair(width,heigth);}
};


#endif //CGAMEOBJ