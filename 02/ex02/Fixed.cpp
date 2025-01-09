#include "./Fixed.hpp"

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	value_ = 0;
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	value_ = (value << fractional_bits_);
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	value_ = static_cast<int>(roundf(value * (1 << fractional_bits_)));
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	value_ = other.value_;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->value_ = fixed.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return this->getRawBits()>= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return this->getRawBits() != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed tmp;

	tmp.setRawBits(this->getRawBits() + fixed.getRawBits());
	return tmp;
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed tmp;

	tmp.setRawBits(this->getRawBits() - fixed.getRawBits());
	return tmp;
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed tmp;
	int64_t result;

	result = static_cast<int64_t>(this->getRawBits()) * static_cast<int64_t>(fixed.getRawBits());
	tmp.setRawBits(static_cast<int>(result >> fractional_bits_));
	return tmp;
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed tmp;
	int64_t result;

	result = (static_cast<int64_t>(this->getRawBits()) << fractional_bits_) / fixed.getRawBits();
	tmp.setRawBits(static_cast<int>(result));
	return tmp;
}

Fixed Fixed::operator++(void)
{
	++value_;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old;

	old = *this;
	++(this->value_);
	return old;
}

Fixed Fixed::operator--(void)
{
	--value_;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old;

	old = *this;
	--(this->value_);
	return old;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return value_;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	value_ = raw;
}

float Fixed::toFloat(void) const
{
	float ret;

	ret = 0;
	ret = static_cast<float>(value_) / (1 << fractional_bits_);
	return ret;
}

int Fixed::toInt(void) const
{
	return value_ >> fractional_bits_;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 >= fixed2)
		return fixed1;
	else
		return fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 >= fixed2)
		return fixed1;
	else
		return fixed2;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 <= fixed2)
		return fixed1;
	else
		return fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 <= fixed2)
		return fixed1;
	else
		return fixed2;
}

std::ostream& operator<<(std::ostream& o, Fixed const& fixed)
{
	o << fixed.toFloat();
	return (o);
}
