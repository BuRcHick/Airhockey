#include "physic_object.hpp"

PhysicObject::PhysicObject()
    : GameObject(TexturesID::None, 0, 0), m_velocity(0, 0), m_angle(0, 0)
{
}

void PhysicObject::move(Vector2D position)
{
    position += m_velocity;

    if (0 != m_angle.length()) {
        position *= m_angle;
    }

    GameObject::move(position);
}

void PhysicObject::setVelocity(Vector2D velocity)
{
    m_velocity = velocity;
}

void PhysicObject::setAngle(Vector2D angle)
{
    m_angle = angle;
}
