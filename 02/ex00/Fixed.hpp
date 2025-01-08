#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{

public:
	Fixed(void);
	Fixed(const Fixed& other);
	~Fixed(void);

	Fixed& operator=(const Fixed& other);

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int value_;
	static const int fractionalBits = 8;
};

#endif
