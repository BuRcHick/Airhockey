#ifndef __POINT_2D_HPP__
#define __POINT_2D_HPP__

#include "vector/vector_2d.hpp"

class Point2D {
public:
    Point2D(float x, float y);

    void setX(float x);
    void setY(float y);

    float getX() { return m_x; }
    float getY() { return m_y; }

    friend Vector2D operator- (Point2D& first, const Point2D & second);
    friend bool operator == (Point2D& first, const Point2D& second);

    Point2D& operator+ (const Vector2D& vector);

private:
    float m_x;
    float m_y;
};

#endif /* __POINT_2D_HPP__ */
