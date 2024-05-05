#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	const Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c (5.2f);
	Fixed c2 (5.00f);

	std::cout << "a : " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "--a : " << --a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "a * b : " << a * b << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "a + c : " << a + c << std::endl;
	std::cout << "a - c : " << a - c << std::endl;
	std::cout << "a / c : " << a / c << std::endl;
	std::cout << "c : " << c << " c2 : " << c2 << std::endl;
	std::cout << "c > c2 : " << (c > c2) << std::endl;
	std::cout << "c = c2 : " << (c == c2) << std::endl;
	std::cout << "c < c2 : " << (c < c2) << std::endl;
	std::cout << "max(a, b) : " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a, b) : " << Fixed::min( a, b ) << std::endl;
	return 0;
}