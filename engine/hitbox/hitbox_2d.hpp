#ifndef __HITBOX_2D_HPP__
#define __HITBOX_2D_HPP__

class HitBox2D {
public:
    HitBox2D(float x, float y, float width, float heigth);

    void move(float x, float y);
    void resize(float width, float heigth);

    bool isHit(const HitBox2D& hitBox);

    float getX() const { return m_x; }
    float getY() const { return m_y; }
    float getWidth() const { return m_width; }
    float getHeight() const { return m_height; }

private:
    float m_x, m_y, m_width, m_height;
};

#endif /* __HITBOX_2D_HPP__ */
