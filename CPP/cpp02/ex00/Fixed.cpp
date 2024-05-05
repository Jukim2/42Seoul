#include "Fixed.hpp"
#include <iostream>

const int Fixed::fractionBits = 8;

Fixed::Fixed() : fixedPointNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixedPointNum = rhs.getRawBits();
	
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPointNum);
}

void Fixed::setRawBits(int const raw)
{
	fixedPointNum = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}