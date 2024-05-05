#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fractionBits = 8;

Fixed::Fixed() : fixedPointNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	fixedPointNum = num << fractionBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
 	fixedPointNum = roundf((num * (1 << fractionBits)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		fixedPointNum = rhs.getRawBits();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Fixed const& num)
{
	float originalValue = ((float)num.getRawBits() / (1 << num.getFractionBits()));
	os << originalValue;
	return os;
}

int	Fixed::getRawBits(void) const
{
	return (fixedPointNum);
}

int Fixed::getFractionBits(void) const
{
	return (fractionBits);
}

void Fixed::setRawBits(int const raw)
{
	fixedPointNum = raw;
}

int Fixed::toInt(void) const
{
	return (fixedPointNum >> fractionBits);
}

float Fixed::toFloat(void) const
{
	return ((float)fixedPointNum / (1 << fractionBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}