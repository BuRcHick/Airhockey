#include "texture_manager.hpp"

TextureManager::~TextureManager()
{
    clear();
}

TextureManager* TextureManager::createManager(SDL_Renderer* renderer)
{
    TextureManager* manager = nullptr;

    if (nullptr == renderer) {
        return nullptr;
    }

    manager = new TextureManager();
    if (nullptr == manager) {
        return nullptr;
    }

    manager->m_renderer = renderer;

    return manager;
}

Texture const* TextureManager::getTextureByID(int textureID)
{
    auto it = m_textures.find(textureID);
    if (it == m_textures.end()) {
        return nullptr;
    }

    return it->second;
}

bool TextureManager::addTexture(int textureID, Texture* texture)
{
    if (m_textures.find(textureID) != m_textures.end() || nullptr == texture) {
        return false;
    }

    m_textures.insert(std::make_pair(textureID, texture));

    return true;
}

bool TextureManager::addTextureByPath(int textureID, const char* path)
{
    Texture* texture = nullptr;

    if (m_textures.find(textureID) != m_textures.end() || nullptr == path) {
        return false;
    }

    texture = Texture::create(path, m_renderer);
    if (nullptr == texture) {
        return false;
    }

    m_textures.insert(std::make_pair(textureID, texture));

    return true;
}

bool TextureManager::drawTextureByID(int textureID, int x, int y)
{
    auto it = m_textures.find(textureID);
    if (it == m_textures.end()) {
        return false;
    }

    it->second->draw(x, y);

    return true;
}

bool TextureManager::removeTexture(int textureID)
{
    auto it = m_textures.find(textureID);
    if (it == m_textures.end()) {
        return false;
    }

    m_textures.erase(it);

    return true;
}

void TextureManager::clear()
{
    m_textures.clear();
}
