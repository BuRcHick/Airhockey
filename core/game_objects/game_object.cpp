#include "game_object.hpp"
#include "texture/texture_manager.hpp"
#include "logger/logger.hpp"

GameObject::GameObject(TexturesID textureID, float x, float y)
    :m_textureID(textureID), m_position(x, y), m_hitBox(0, 0, 0, 0)
{
    TextureManager* manager = TextureManager::getManager();
    Texture const* texture = manager->getTextureByID((int)m_textureID);

    if (nullptr != texture) {
        m_hitBox = HitBox2D(x, y, texture->getWidth(), texture->getHeight());
    }
}

bool GameObject::isHit(const GameObject& object)
{
    return m_hitBox.isHit(object.m_hitBox);
}

bool GameObject::isHit(const HitBox2D& hitbox)
{
    return m_hitBox.isHit(hitbox);
}


void GameObject::move(Vector2D position)
{
    m_position = position;
}

bool GameObject::resize(int width, int height)
{
    if (width < 0 || height < 0) {
        LOG_WARNING("Invalid input: width = %d, height = %d\n", width, height);

        return false;
    }

    m_width = width;
    m_height = height;

    return true;
}

void GameObject::draw()
{
    TextureManager* manager = TextureManager::getManager();

    manager->drawTextureByID((int)m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height);
}
