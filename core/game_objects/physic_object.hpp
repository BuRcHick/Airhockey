#ifndef __PHYSIC_OBJECT_HPP__
#define __PHYSIC_OBJECT_HPP__

#include "game_object.hpp"

class PhysicObject : virtual public GameObject {
public:
    PhysicObject();
    virtual ~PhysicObject() = default;

    virtual void move(Vector2D position) override;
    void setVelocity(Vector2D velocity);
    void setAngle(Vector2D angle);

private:
    Vector2D m_velocity;
    Vector2D m_angle;
};

#endif /* __PHYSIC_OBJECT_HPP__ */
