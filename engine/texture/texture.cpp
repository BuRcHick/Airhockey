#include "texture.hpp"
#include "SDL2/SDL_image.h"
#include "logger/logger.hpp"

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
        LOG_WARNING("Invalid input: path = %p, renderer = %p\n", path, renderer);

        return nullptr;
    }

    new_texture = new Texture();
    if (nullptr == new_texture) {
        LOG_ERROR("Out of memory\n");

        return nullptr;
    }

    new_texture->m_renderer = renderer;
    new_texture->m_texture = IMG_LoadTexture(new_texture->m_renderer, path);

    if (nullptr == new_texture->m_texture) {
        LOG_ERROR("Failed to load texture: %s\n", path);
        delete new_texture;

        return nullptr;
    }

    SDL_QueryTexture(new_texture->m_texture, nullptr, nullptr,
                     &new_texture->m_width, &new_texture->m_height);

    return new_texture;
}

void Texture::draw(int x, int y, int width, int height)
{
    if (nullptr == m_texture || nullptr == m_renderer) {
        LOG_WARNING("Invalid input: m_texture = %p, m_renderer = %p\n", m_texture, m_renderer);
        return;
    }

    if (x < 0 || y < 0) {
        LOG_WARNING("Invalid input: x = %d, y = %d\n", x, y);
        return;
    }

    SDL_Rect rect = {
        .x = x,
        .y = y,
        .w = width,
        .h = height
    };

    SDL_RenderCopy(m_renderer, m_texture, NULL, &rect);
}

bool Texture::resize(int width, int height)
{
    if (width < 0 || height < 0) {
        LOG_WARNING("Invalid input: width = %d, height = %d\n", width, height);

        return false;
    }

    m_width = width;
    m_height = height;

    return true;
}
