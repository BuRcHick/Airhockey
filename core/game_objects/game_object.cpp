#include "game_object.hpp"
#include "texture/texture_manager.hpp"

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


void GameObject::move(Vector2D& position)
{
    m_position += position;
}

void GameObject::draw()
{
    TextureManager* manager = TextureManager::getManager();

    manager->drawTextureByID((int)m_textureID, m_position.getX(), m_position.getY());
}
