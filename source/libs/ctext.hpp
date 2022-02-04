#ifndef CTEXT
#define CTEXT
#include "cgameobj.hpp"
#include "SDL2/SDL_ttf.h"

class CText : public CGameObj
{
private:
public:
    CText(/* args */);
    ~CText();
    bool createText(const std::string&,const std::string&, SDL_Color,int, SDL_Renderer*);
    void renderTexture(SDL_Renderer*);
};

#endif //CTEXT
