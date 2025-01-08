#include "./Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	value_ = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	value_ = (value << fractional_bits_);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	value_ = static_cast<int>(roundf(value * (1 << fractional_bits_)));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	value_ = other.value_;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value_ = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value_;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value_ = raw;
}

float	Fixed::toFloat(void) const
{
	float	ret;

	ret = 0;
	ret = static_cast<float>(value_) / static_cast<float>(1 << fractional_bits_);
	return ret;
}

int	Fixed::toInt(void) const
{
	return value_ >> fractional_bits_;
}

std::ostream	&operator<<(std::ostream& o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}

