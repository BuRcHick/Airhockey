#ifndef __GAME_OBJECT_HPP__
#define __GAME_OBJECT_HPP__

#include "common.hpp"
#include "vector/vector_2d.hpp"
#include "hitbox/hitbox_2d.hpp"
#include "event/event.hpp"

class GameObject {
public:
    GameObject(TexturesID textureID, float x, float y);
    virtual ~GameObject() = default;

    virtual void move(Vector2D position);
    virtual void draw();
    virtual void handleEvent(Event* event) = 0;
    virtual bool isHit(const GameObject& object);
    virtual bool isHit(const HitBox2D& hitbox);

    bool resize(int width, int height);

    TexturesID getTexture() const { return m_textureID; }
    Vector2D getPosition() const { return m_position; }

private:
    Vector2D m_position;
    TexturesID m_textureID;
    HitBox2D m_hitBox;
    int m_width, m_height;
};

#endif /* __GAME_OBJECT_HPP__ */
