#include "hockey_puck.hpp"
#include "texture/texture_manager.hpp"
#include "logger/logger.hpp"
#include <chrono>

HockeyPuck::HockeyPuck()
    : PhysicObject(), GameObject(TexturesID::HockeyPuck, 0, 0),
    m_friction(0, 0)
{
}

void HockeyPuck::setFriction(Vector2D friction)
{
    m_friction = friction;
}

void HockeyPuck::update(float dt)
{
    PhysicObject::update(dt);

    Vector2D currentVelocity = getVelocity();

    if (currentVelocity.getY() < 0 && m_friction.getY() < 0) {
        setVelocity(Vector2D(0, 0));
        m_friction = Vector2D(0, 0);
        return;
    }

    if (currentVelocity.getY() > 0 && m_friction.getY() > 0) {
        setVelocity(Vector2D(0, 0));
        m_friction = Vector2D(0, 0);
        return;
    }

    currentVelocity = currentVelocity + m_friction * dt;
    setVelocity(currentVelocity);

}

void HockeyPuck::handleGameEvent(GameEvent& event)
{
    switch (event.type) {
        case GameEventType::Tick: {
            break;
        }
        default:
            break;
    }
}

void HockeyPuck::handleEvent(Event* event)
{
    switch (event->type) {
        case EventType::GameEvent:
            handleGameEvent(event->data.game_event);

            break;
        default:
            break;
    }
}
