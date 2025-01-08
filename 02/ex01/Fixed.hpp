#ifndef	FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed(void);
		
		Fixed& operator=(const Fixed& other);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;

	private:
		int			value_;
		static const int	fractional_bits_ = 8;
};

std::ostream &operator<<(std::ostream& o, Fixed const & fixed);

#endif
