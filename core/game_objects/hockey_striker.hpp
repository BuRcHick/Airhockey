#ifndef __HOCKEY_STRIKER_HPP__
#define __HOCKEY_STRIKER_HPP__

#include "hitbox/hitbox_2d.hpp"
#include "physic_object.hpp"

class HockeyStriker : virtual public PhysicObject {
public:
    HockeyStriker();
    virtual ~HockeyStriker() = default;

    virtual bool isHit(const GameObject& object) override;
    virtual void handleEvent(Event* event) override;

    virtual bool resize(int width, int height) override;
    virtual void draw() override;
    virtual void setPosition(Point2D point) override;

    const HitBox2D& getTopHitBox() const { return m_topHitBox; }
    const HitBox2D& getMiddleHitBox() const { return m_middleHitBox; }
    const HitBox2D& getBottomHitBox() const { return m_buttomHitBox; }

private:
    void handleSDLEvent(SDL_Event& event);

    HitBox2D m_topHitBox;
    HitBox2D m_middleHitBox;
    HitBox2D m_buttomHitBox;
};

#endif /* __HOCKEY_STRIKER_HPP__ */
