#include <ctgmath>

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

bool operator == (Point2D& first, const Point2D& second)
{
    return (std::fabs(first.m_x) == std::fabs(second.m_x))
           && (std::fabs(first.m_y) == std::fabs(second.m_y));
}

Point2D operator* (Point2D& point, const Vector2D& vector)
{
    Point2D result = point;

    result.setX(vector.getX() * point.getX());
    result.setY(vector.getY() * point.getY());

    return result;
}
