#ifndef __GAME_OBJECT_HPP__
#define __GAME_OBJECT_HPP__

#include "common.hpp"
#include "vector/vector_2d.hpp"
#include "hitbox/hitbox_2d.hpp"

class GameObject {
public:
    GameObject(TexturesID textureID, float x, float y);
    virtual ~GameObject() = default;

    virtual void move(Vector2D& position);
    virtual void draw();
    virtual void handleEvent() = 0;
    virtual bool isHit(const GameObject& object);

    TexturesID getTexture() const { return m_textureID; }
    Vector2D getPosition() const { return m_position; }

private:
    Vector2D m_position;
    TexturesID m_textureID;
    HitBox2D m_hitBox;
};

#endif /* __GAME_OBJECT_HPP__ */
