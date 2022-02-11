#ifndef __VECTOR_2D_HPP__
#define __VECTOR_2D_HPP__

#include <cmath>

class Vector2D {
public:
    Vector2D(float x, float y);

    void setX(float x);
    void setY(float y);

    float getX() const { return m_x; }
    float getY() const { return m_y; }

    Vector2D& operator +=(Vector2D& vector);
    friend Vector2D operator +(Vector2D& vector1, const Vector2D& vector2);

    Vector2D& operator -=(Vector2D& vector);
    friend Vector2D operator -(Vector2D& vector1, const Vector2D& vector2);

    Vector2D& operator *=(Vector2D& vector);
    friend Vector2D operator *(Vector2D& vector1, const Vector2D& vector2);

    Vector2D& operator *=(float scale);
    friend Vector2D operator *(Vector2D& vector1, float scale);

    Vector2D& operator /=(float scale);

    float length();
    float lengthSqrt();

    Vector2D normalize();

private:
    float m_x, m_y;
};

#endif /*__VECTOR_2D_HPP__*/
