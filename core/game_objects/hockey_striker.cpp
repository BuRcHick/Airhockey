#include "hockey_striker.hpp"
#include "texture/texture_manager.hpp"

HockeyStriker::HockeyStriker()
    : PhysicObject(), GameObject(TexturesID::HockeyStriker, 0, 0),
    m_topHitBox(0, 0, 0, 0),
    m_middleHitBox(0, 0, 0, 0),
    m_buttomHitBox(0, 0, 0, 0)
{
    TextureManager* manager = TextureManager::getManager();
    Texture const* texture = manager->getTextureByID((int)TexturesID::HockeyStriker);
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

void HockeyStriker::handleSDLEvent(SDL_Event& event)
{
    switch (event.type) {
        case SDL_MOUSEMOTION:
            move(Vector2D(event.motion.x, event.motion.y));

            break;
        default:
            break;
    }
}

void HockeyStriker::handleEvent(Event* event)
{
    switch (event->type) {
        case EventType::SDL_Event:
            handleSDLEvent(event->data.sdl_event);

            break;
        default:
            break;
    }
}
