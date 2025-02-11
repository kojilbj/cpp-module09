#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed(void);

	Fixed& operator=(const Fixed& fixed);

	bool operator>(const Fixed& fixed) const;
	bool operator<(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed) const;
	bool operator<=(const Fixed& fixed) const;

	bool operator==(const Fixed& fixed) const;
	bool operator!=(const Fixed& fixed) const;

	Fixed operator+(const Fixed& fixed) const;
	Fixed operator-(const Fixed& fixed) const;

	Fixed operator*(const Fixed& fixed) const;
	Fixed operator/(const Fixed& fixed) const;

	Fixed operator++(void);
	Fixed operator++(int);

	Fixed operator--(void);
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed& max(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed& min(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);

private:
	int value_;
	static const int fractional_bits_ = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& fixed);

#endif
