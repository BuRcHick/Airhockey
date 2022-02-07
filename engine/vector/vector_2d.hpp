#ifndef __VECTOR_2D_HPP__
#define __VECTOR_2D_HPP__

#include <cmath>

class Vector2D {
public:
    Vector2D(float x, float y);

    void setX(float x) { m_x = x; };
    void setY(float y) { m_y = y; };

    float getX() { return m_x; }
    float getY() { return m_y; }

    Vector2D& operator +=(Vector2D& vector)
    {
        m_x += vector.m_x;
        m_y += vector.m_y;

        return *this;
    }

    friend Vector2D operator +(Vector2D& vector1, const Vector2D& vector2)
    {
        return Vector2D(vector1.m_x + vector2.m_x, vector1.m_y + vector2.m_y);
    }

    Vector2D& operator -=(Vector2D& vector)
    {
        m_x -= vector.m_x;
        m_y -= vector.m_y;

        return *this;
    }

    friend Vector2D operator -(Vector2D& vector1, const Vector2D& vector2)
    {
        return Vector2D(vector1.m_x - vector2.m_x, vector1.m_y - vector2.m_y);
    }

    Vector2D& operator *=(Vector2D& vector)
    {
        m_x *= vector.m_x;
        m_y *= vector.m_y;

        return *this;
    }

    friend Vector2D operator *(Vector2D& vector1, const Vector2D& vector2)
    {
        return Vector2D(vector1.m_x * vector2.m_x, vector1.m_y * vector2.m_y);
    }

    float length()
    {
        return std::sqrt(m_x * m_x + m_y * m_y);
    }

private:
    float m_x, m_y;
};

#endif /*__VECTOR_2D_HPP__*/
