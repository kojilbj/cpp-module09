#include <string>
#include <iostream>
#include "./Fixed.hpp"
#include "./Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point);

int	main(void)
{
	Point a(10, 10);
	Point b(10, 10);
	Point c(20, 0);
	Point point(5, 0);

	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}