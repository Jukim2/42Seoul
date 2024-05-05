#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int fixedPointNum;
		static const int fractionBits;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif