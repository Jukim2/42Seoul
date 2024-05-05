#include <iostream>
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main( void ) 
{
	Point A(2, 0);
	Point B(0, 2);
	Point C(0, 0);
	Point D(1, 1);

	std::cout << bsp(A, B, C, D) << std::endl;

	return 0;
}