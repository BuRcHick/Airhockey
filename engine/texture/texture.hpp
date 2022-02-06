#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include "SDL2/SDL.h"

class Texture {
public:
    virtual ~Texture();

    static Texture* create(const char* path, SDL_Renderer* renderer);

    virtual void draw(int x, int y);
    virtual bool resize(int width, int height);

protected:
    Texture() = default;

private:
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    int m_width, m_height;
};

#endif /* __TEXTURE_HPP__ */
