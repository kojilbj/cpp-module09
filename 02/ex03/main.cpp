#include <string>
#include <iostream>
#include "./Fixed.hpp"
#include "./Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point);

int	main(void)
{
	Point a(0, 0);
	Point b(0, 0.5f);
	Point c(0.5f, 0);
	Point point(0.03f, 0.03f);

	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}
