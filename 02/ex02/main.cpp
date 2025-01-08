#include "./Fixed.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "---------------- Subject Test ----------------" << std::endl;
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;
	std::cout << "---------------- Own Test ----------------" << std::endl;

	Fixed c(2.45f);
	Fixed d(0.1f);

	std::cout << "2.45 + 0.1" << std::endl;
	std::cout << "\t2.45: " << Fixed(2.45f).getRawBits() << " 0.1: " << Fixed(0.1f).getRawBits() << std::endl;
	std::cout << "\t" << c + d << ": " << (c + d).getRawBits()<< std::endl;
	std::cout << "2.45 - 0.1" << std::endl;
	std::cout << "\t2.45: " << Fixed(2.45f).getRawBits() << " 0.1: " << Fixed(0.1f).getRawBits() << std::endl;
	std::cout << "\t" << c - d << ": " << (c - d).getRawBits()<< std::endl;
	std::cout << "2.45 / 0.1" << std::endl;
	std::cout << "\t2.45: " << Fixed(2.45f).getRawBits() << " 0.1: " << Fixed(0.1f).getRawBits() << std::endl;
	std::cout << "\t" << c / d << ": " << (c / d).getRawBits()<< std::endl;
	std::cout << "2.45 * 0.1" << std::endl;
	std::cout << "\t2.45: " << Fixed(2.45f).getRawBits() << " 0.1: " << Fixed(0.1f).getRawBits() << std::endl;
	std::cout << "\t" << c * d << ": " << (c * d).getRawBits()<< std::endl;

	std::cout << std::endl;

	Fixed right;
	Fixed left;

	right.setRawBits(1);
	left.setRawBits(1);
	std::cout << "right: " << right << " left: " << left << std::endl;
	std::cout << "right == left :" << (right == left) << std::endl;
	std::cout << "right > left :" << (right > left) << std::endl;
	std::cout << "right < left :" << (right < left) << std::endl;
	std::cout << "right => left :" << (right >= left) << std::endl;
	std::cout << "right =< left :" << (right <= left) << std::endl;
	std::cout << "right != left :" << (right != left) << std::endl;
	std::cout << std::endl;

	left.setRawBits(2);
	std::cout << "right: " << right << " left: " << left << std::endl;
	std::cout << "right == left :" << (right == left) << std::endl;
	std::cout << "right > left :" << (right > left) << std::endl;
	std::cout << "right < left :" << (right < left) << std::endl;
	std::cout << "right => left :" << (right >= left) << std::endl;
	std::cout << "right =< left :" << (right <= left) << std::endl;
	std::cout << "right != left :" << (right != left) << std::endl;
	std::cout << std::endl;
	std::cout << "---------------- Over-flow Test ----------------" << std::endl;
	Fixed	k;
	Fixed	z;

	k.setRawBits(INT_MAX / 4);
	z.setRawBits(3);
	std::cout << k * z << std::endl;
	return 0;
}
