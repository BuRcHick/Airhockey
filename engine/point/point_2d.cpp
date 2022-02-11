#include "point_2d.hpp"

Point2D::Point2D(float x, float y)
    : m_x{x}, m_y{y}
{
}

void Point2D::setX(float x)
{
    m_x = x;
}

void Point2D::setY(float y)
{
    m_y = y;
}

Vector2D operator- (Point2D& first, const Point2D& second)
{
    return Vector2D(first.m_x - second.m_x, first.m_y - second.m_y);
}

Point2D& Point2D::operator+(const Vector2D &vector)
{
    m_x += vector.getX();
    m_y += vector.getY();

    return *this;
}
