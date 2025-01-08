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
	std::cout << c + d << std::endl;
	std::cout << "2.45 - 0.1" << std::endl;
	std::cout << c - d << std::endl;
	std::cout << "2.45 / 0.1" << std::endl;
	std::cout << c / d << std::endl;
	std::cout << "2.45 * 0.1" << std::endl;
	std::cout << c * d << std::endl;
	return 0;
}
