#include "hitbox_2d.hpp"

HitBox2D::HitBox2D(float x, float y, float width, float heigth)
    :m_x(x), m_y(y), m_width(width), m_height(heigth)
{
}

void HitBox2D::move(float x, float y)
{
    m_x = x;
    m_y = y;
}

void HitBox2D::resize(float width, float heigth)
{
    m_width = width;
    m_height = heigth;
}

bool HitBox2D::isHit(const HitBox2D& hitBox)
{
    bool hit_x = false;
    bool hit_y = false;

    if (m_x <= (hitBox.m_x + hitBox.m_width)) {
        if (hitBox.m_x <= (m_x + m_width)) {
            hit_x = true;
        }
    }

    if (m_y <= (hitBox.m_y + hitBox.m_height)) {
        if (hitBox.m_y <= (m_y + m_height)) {
            hit_y = true;
        }
    }

    return hit_x && hit_y;
}
