#ifndef __HOCKEY_STRIKER_HPP__
#define __HOCKEY_STRIKER_HPP__

#include "hitbox/hitbox_2d.hpp"
#include "physic_object.hpp"

class HockeyStriker : virtual public PhysicObject {
public:
    HockeyStriker();
    virtual ~HockeyStriker() = default;

    virtual void handleEvent() override;
    virtual bool isHit(const GameObject& object) override;

private:
    HitBox2D m_topHitBox;
    HitBox2D m_middleHitBox;
    HitBox2D m_buttomHitBox;
};

#endif /* __HOCKEY_STRIKER_HPP__ */
