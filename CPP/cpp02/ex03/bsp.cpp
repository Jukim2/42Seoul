#include "Point.hpp"
#include <iostream>

float crossProduct(Point A, Point B, Point C) {
    return (C.getX() - A.getX()) * (C.getY() - B.getY()) - (C.getY() - A.getY()) * (C.getX() - B.getX());
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    float crossABP = crossProduct(a, b, point);
    float crossBCP = crossProduct(b, c, point);
    float crossCAP = crossProduct(c, a, point);

    if ((crossABP > 0 && crossBCP > 0 && crossCAP > 0) ||
        (crossABP < 0 && crossBCP < 0 && crossCAP < 0)) {
        return (true);
    } else {
        return (false);
    }
}


