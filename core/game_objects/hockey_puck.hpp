#ifndef __HOCKEY_PUCK_HPP__
#define __HOCKEY_PUCK_HPP__

#include "physic_object.hpp"

class HockeyPuck : virtual public PhysicObject {
public:
    HockeyPuck();
    ~HockeyPuck();

    virtual bool isHit(const GameObject& object) override;
    virtual void handleEvent(Event* event) override;
};

#endif /* __HOCKEY_PUCK_HPP__ */
