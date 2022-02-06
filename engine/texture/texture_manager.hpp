#ifndef __TEXTURE_MANAGER_HPP__
#define __TEXTURE_MANAGER_HPP__

#include "texture.hpp"

#include <unordered_map>

class TextureManager {
public:
    ~TextureManager();

    static TextureManager* createManager(SDL_Renderer* renderer);

    Texture const* getTextureByID(int textureID);
    bool addTexture(int textureID, Texture* texture);
    bool addTextureByPath(int textureID, const char* path);
    bool drawTextureByID(int textureID, int x, int y);
    bool removeTexture(int textureID);

    void clear();

protected:
    TextureManager() = default;

private:
    SDL_Renderer* m_renderer;
    std::unordered_map<int, Texture*> m_textures;
};

#endif /* __TEXTURE_MANAGER_HPP__ */
