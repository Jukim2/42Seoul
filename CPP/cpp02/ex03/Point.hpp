#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
        Fixed modifiableX;
        Fixed modifiableY;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& copy);
        Point& operator=(const Point& rhs);
        ~Point();
        float getX() const;
        float getY() const;
};

#endif