#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixedPointNum;
		static const int fractionBits;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int getFractionBits(void) const;
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, Fixed const& num);

#endif