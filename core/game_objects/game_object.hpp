#ifndef __GAME_OBJECT_HPP__
#define __GAME_OBJECT_HPP__

#include "common.hpp"
#include "event/event.hpp"
#include "hitbox/hitbox_2d.hpp"
#include "point/point_2d.hpp"
#include "common/limits.hpp"

#include <utility>

class GameObject {
public:
    GameObject(TexturesID textureID, float x, float y);
    virtual ~GameObject() = default;

    virtual void setPosition(Point2D point);
    virtual void draw();

    virtual void update(float dt) = 0;
    virtual void handleEvent(Event* event) = 0;

    virtual bool isHit(const GameObject& object);
    virtual bool isHit(const HitBox2D& hitbox);

    virtual bool resize(int width, int height);

    TexturesID getTexture() const { return m_textureID; }
    Point2D getPosition() const { return m_position; }
    std::pair<int, int> getSize() const
    {
        return std::make_pair(m_width, m_height);
    }

    void setWidthLimits(float min, float max);
    void setHeightLimits(float min, float max);

    Point2D limitPosition(Point2D position);

protected:
    virtual void drawHitbox();

private:
    Point2D m_position;
    TexturesID m_textureID;
    HitBox2D m_hitBox;
    int m_width, m_height;
    Limits    m_widhtLimits;
    Limits    m_heightLimits;
};

#endif /* __GAME_OBJECT_HPP__ */
