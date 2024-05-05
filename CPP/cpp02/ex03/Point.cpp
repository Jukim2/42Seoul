#include "Point.hpp"

Point::Point() : x(), y()
{
    
}

Point::Point(const float x, const float y) : x(x), y(y)
{

}

Point::Point(const Point& copy) : x(copy.getX()), y(copy.getY())
{
  
}

Point& Point::operator=(const Point& rhs)
{
    modifiableX = rhs.getX();
    modifiableY = rhs.getY();

    return (*this);
}

Point::~Point()
{
    
}

float Point::getX() const
{
	return (x.toFloat());
}

float Point::getY() const
{
	return (y.toFloat());
}
