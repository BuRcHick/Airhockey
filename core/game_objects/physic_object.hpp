#ifndef __PHYSIC_OBJECT_HPP__
#define __PHYSIC_OBJECT_HPP__

#include "game_object.hpp"

enum class Direction {
    Top = 0,
    Bottom
};

class PhysicObject : virtual public GameObject {
public:
    PhysicObject();
    virtual ~PhysicObject() = default;

    void setVelocity(Vector2D velocity);
    void setAngle(Vector2D angle);

    virtual void update(float dt) override;

    Vector2D getVelocity() const { return m_velocity; }
    Vector2D getAngle() const { return m_angle; }

    void setDirection(Direction direction) { m_direction = direction; }
    Direction getDirection() { return m_direction; }

private:
    Vector2D m_velocity;
    Vector2D m_angle;
    Direction m_direction;
};

#endif /* __PHYSIC_OBJECT_HPP__ */
