#ifndef __HOCKEY_PUCK_HPP__
#define __HOCKEY_PUCK_HPP__

#include "physic_object.hpp"

#include <mutex>

class HockeyPuck : virtual public PhysicObject {
public:
    HockeyPuck();
    virtual ~HockeyPuck() = default;

    virtual void handleEvent(Event* event) override;
    virtual void update(float dt) override;
    void setFriction(Vector2D friction);
    Vector2D getFriction() const { return m_friction; }

private:
    void handleGameEvent(GameEvent& event);

    Vector2D m_friction;
    std::mutex m_mutex;
};

#endif /* __HOCKEY_PUCK_HPP__ */
