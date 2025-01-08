#include "./Fixed.hpp"
#include <iostream>
#include <string>

int main(void)
{
	std::cout << "---------------- Subject Test ----------------" << std::endl;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << std::endl;
	std::cout << "---------------- Own Test ----------------" << std::endl;

	Fixed e;
	std::cout << std::endl;

	std::cout << "setRawBits(1)" << std::endl;
	e.setRawBits(1);
	std::cout << "e is " << e.toFloat() << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "setRawBits(128)" << std::endl;
	e.setRawBits(128);
	std::cout << "e is " << e.toFloat() << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "setRawBits(255)" << std::endl;
	e.setRawBits(255);
	std::cout << "e is " << e.toFloat() << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "setRawBits(256)" << std::endl;
	e.setRawBits(256);
	std::cout << "e is " << e.toFloat() << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "setRawBits(257)" << std::endl;
	e.setRawBits(257);
	std::cout << "e is " << e.toFloat() << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "setRawBits(511)" << std::endl;
	e.setRawBits(511);
	std::cout << "e is " << e.toFloat() << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	std::cout << "setRawBits(512)" << std::endl;
	e.setRawBits(512);
	std::cout << "e is " << e.toFloat() << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	return 0;
}
