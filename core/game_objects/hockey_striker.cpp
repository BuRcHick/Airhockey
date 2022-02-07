#include "hockey_striker.hpp"
#include "texture/texture_manager.hpp"

HockeyStriker::HockeyStriker()
    : PhysicObject(), GameObject(TexturesID::HockeyStriker, 0, 0),
    m_topHitBox(0, 0, 0, 0),
    m_middleHitBox(0, 0, 0, 0),
    m_buttomHitBox(0, 0, 0, 0)
{
    TextureManager* manager = TextureManager::getManager();
    Texture const* texture = manager->getTextureByID(TexturesID::HockeyStriker);
    if (nullptr != texture) {
        int heigth = texture->getHeight();
        int width = texture->getWidth();
        m_topHitBox.resize(width, 5);
        m_buttomHitBox.resize(width, 5);
        m_middleHitBox.resize(width, heigth - 10);
    }
}

bool HockeyStriker::isHit(const GameObject& object)
{
    /* TODO */
    return false;
}

void HockeyStriker::handleEvent()
{
    /* TODO */
}
