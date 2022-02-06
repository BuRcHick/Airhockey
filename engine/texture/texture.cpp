#include "texture.hpp"
#include "SDL2/SDL_image.h"

Texture::~Texture()
{
    if (nullptr != m_texture) {
        SDL_DestroyTexture(m_texture);
    }
}

Texture* Texture::create(const char* path, SDL_Renderer* renderer)
{
    Texture* new_texture = nullptr;

    if (nullptr == path || nullptr == renderer) {
        return nullptr;
    }

    new_texture = new Texture();
    if (nullptr == new_texture) {
        return nullptr;
    }

    new_texture->m_renderer = renderer;
    new_texture->m_texture = IMG_LoadTexture(new_texture->m_renderer, path);

    SDL_QueryTexture(new_texture->m_texture, nullptr, nullptr,
                     &new_texture->m_width, &new_texture->m_height);

    return new_texture;
}

void Texture::draw(int x, int y)
{
    if (nullptr == m_texture || nullptr == m_renderer) {
        return;
    }

    if (x < 0 || y < 0) {
        return;
    }

    SDL_Rect rect = {
        .x = x,
        .y = y,
        .w = m_width,
        .h = m_height
    };

    SDL_RenderCopy(m_renderer, m_texture, NULL, &rect);
}

bool Texture::resize(int width, int height)
{
    if (width < 0 || height < 0) {
        return false;
    }

    m_width = width;
    m_height = height;

    return true;
}
