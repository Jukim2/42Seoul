#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fractionBits = 8;

Fixed::Fixed() : fixedPointNum(0)
{

}

Fixed::Fixed(const int num)
{
	fixedPointNum = num * (1 << fractionBits);
}

Fixed::Fixed(const float num)
{
 	fixedPointNum = roundf((num * (1 << fractionBits)));
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
	{
		fixedPointNum = rhs.fixedPointNum;
	}
	return (*this);
}

Fixed& Fixed::operator++()
{
	fixedPointNum++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	fixedPointNum++;
	return (tmp);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed result(toFloat() + rhs.toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed result(toFloat() - rhs.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed result(toFloat() / rhs.toFloat());
	return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed result(toFloat() * rhs.toFloat());
	return (result);
}

bool Fixed::operator<(const Fixed& rhs) const
{
	if (fixedPointNum < rhs.fixedPointNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	if (fixedPointNum <= rhs.fixedPointNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator>(const Fixed& rhs) const
{
	if (fixedPointNum > rhs.fixedPointNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	if (fixedPointNum >= rhs.fixedPointNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed& rhs) const
{
	if (fixedPointNum == rhs.fixedPointNum)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	if (fixedPointNum != rhs.fixedPointNum)
		return (true);
	else
		return (false);
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

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return (second);
	else
		return (first);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return (second);
	else
		return (first);
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	else
		return (second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	else
		return (second);
}

Fixed::~Fixed()
{
	
}