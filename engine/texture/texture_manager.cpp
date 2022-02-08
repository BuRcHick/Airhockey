#include "texture_manager.hpp"
#include "logger/logger.hpp"

TextureManager* TextureManager::m_manager = nullptr;

TextureManager::~TextureManager()
{
    clear();
}

TextureManager* TextureManager::getManager()
{

    if (nullptr == m_manager) {
        m_manager = new TextureManager();
    }

    return m_manager;
}

Texture const* TextureManager::getTextureByID(int textureID)
{
    auto it = m_textures.find(textureID);
    if (it == m_textures.end()) {
        LOG_WARNING("Failed to find texture: textureID = %d\n", textureID);

        return nullptr;
    }

    return it->second;
}

bool TextureManager::addTexture(int textureID, Texture* texture)
{
    if (m_textures.find(textureID) != m_textures.end() || nullptr == texture) {
        LOG_WARNING("Failed to add textureID = %d. Texture already exist\n", textureID);

        return false;
    }

    m_textures.insert(std::make_pair(textureID, texture));

    return true;
}

bool TextureManager::addTextureByPath(int textureID, const char* path)
{
    Texture* texture = nullptr;

    if (nullptr == m_renderer) {
        LOG_WARNING("Renderer is not initialized\n");

        return false;
    }

    if (m_textures.find(textureID) != m_textures.end() || nullptr == path) {
        LOG_WARNING("Invalid input: textureID = %d, path = %p\n", textureID, path);

        return false;
    }

    texture = Texture::create(path, m_renderer);
    if (nullptr == texture) {
        LOG_ERROR("Failed to create texture\n");

        return false;
    }

    m_textures.insert(std::make_pair(textureID, texture));

    return true;
}

bool TextureManager::drawTextureByID(int textureID, int x, int y, int width, int height)
{
    auto it = m_textures.find(textureID);
    if (it == m_textures.end()) {
        LOG_WARNING("Failed to find texture: textureID = %d\n", textureID);

        return false;
    }

    it->second->draw(x, y, width, height);

    return true;
}

bool TextureManager::removeTexture(int textureID)
{
    auto it = m_textures.find(textureID);
    if (it == m_textures.end()) {
        LOG_WARNING("Failed to find texture: textureID = %d\n", textureID);

        return false;
    }

    m_textures.erase(it);

    return true;
}


bool TextureManager::setRenderer(SDL_Renderer* renderer)
{
    if (nullptr == renderer) {
        LOG_WARNING("Renderer has been set already\n");

        return false;
    }

    m_renderer = renderer;

    return true;
}

void TextureManager::clear()
{
    m_textures.clear();
}
