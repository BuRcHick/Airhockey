#include "vector_2d.hpp"

Vector2D::Vector2D(float x, float y) 
    : m_x(x), m_y(y)
{};

void Vector2D::setX(float x)
{
    m_x = x;
};

void Vector2D::setY(float y)
{
    m_y = y;
};

Vector2D& Vector2D::operator +=(Vector2D& vector)
{
    m_x += vector.m_x;
    m_y += vector.m_y;

    return *this;
}

Vector2D operator +(Vector2D& vector1, const Vector2D& vector2)
{
    return Vector2D(vector1.m_x + vector2.m_x, vector1.m_y + vector2.m_y);
}

Vector2D& Vector2D::operator -=(Vector2D& vector)
{
    m_x -= vector.m_x;
    m_y -= vector.m_y;

    return *this;
}

Vector2D operator -(Vector2D& vector1, const Vector2D& vector2)
{
    return Vector2D(vector1.m_x - vector2.m_x, vector1.m_y - vector2.m_y);
}

Vector2D& Vector2D::operator *=(Vector2D& vector)
{
    m_x *= vector.m_x;
    m_y *= vector.m_y;

    return *this;
}

Vector2D operator *(Vector2D& vector1, const Vector2D& vector2)
{
    return Vector2D(vector1.m_x * vector2.m_x, vector1.m_y * vector2.m_y);
}

Vector2D operator *(Vector2D& vector1, float scale)
{
    return Vector2D(vector1.m_x * scale, vector1.m_y * scale);
}

Vector2D& Vector2D::operator*=(float scale)
{
    m_x *= scale;
    m_y *= scale;

    return *this;
}

Vector2D& Vector2D::operator/=(float scale)
{
    m_x /= scale;
    m_y /= scale;

    return *this;
}

float Vector2D::length()
{
    return std::sqrt(m_x * m_x + m_y * m_y);
}

float Vector2D::lengthSqrt()
{
    return std::sqrt(m_x * m_x + m_y * m_y);
}

Vector2D Vector2D::normalize()
{
    return Vector2D(m_x / length(), m_y / length());
}
