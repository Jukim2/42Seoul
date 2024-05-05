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
		Fixed& operator++(); // Prefix
		Fixed operator++(int); //Postfix
		Fixed& operator--();
		Fixed operator--(int);
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;
		bool operator>(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;
		~Fixed();
		int getRawBits(void) const;
		int getFractionBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);
};

std::ostream& operator<<(std::ostream& os, Fixed const& num);

#endif