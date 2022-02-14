#include "physic_object.hpp"

#include <cmath>

PhysicObject::PhysicObject()
    : GameObject(TexturesID::None, 0, 0), m_velocity(0, 0), m_angle(0, 0)
{
}

void PhysicObject::setVelocity(Vector2D velocity)
{
    m_velocity = velocity;
}

void PhysicObject::setAngle(Vector2D angle)
{
    m_angle = angle;
}

void PhysicObject::update(float dt)
{
    Point2D position = getPosition();

    if (m_angle.lengthSqrt() > m_velocity.lengthSqrt()) {
        m_angle = Vector2D(0, 0);
        m_velocity = Vector2D(0, 0);
    }

    position = position + m_velocity * dt;
    position = position + m_angle;

    setPosition(position);
}

