#include "./Point.hpp"
#include <iostream>

//calcurate triangle area
static Fixed	triangle_area(const Point a, const Point b, const Point c)
{
	Fixed	area;

	area = ((a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y())) / 2);
	if (area < 0)
		area = area * -1;
	return (area);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	origin_area;
	Fixed	area1;
	Fixed	area2;
	Fixed	area3;
	Fixed	sum;

	origin_area = triangle_area(a, b, c);
	// std::cout << "origin_area: " << origin_area.toFloat() << std::endl;
	area1 = triangle_area(a, b, point);
	// std::cout << "area1: " << area1.toFloat() << std::endl;
	if (area1 == 0)
		return (false);
	area2 = triangle_area(a, point, c);
	// std::cout << "area2: " << area2.toFloat() << std::endl;
	if (area2 == 0)
		return (false);
	area3 = triangle_area(point, b, c);
	// std::cout << "area3: " << area3.toFloat() << std::endl;
	if (area3 == 0)
		return (false);
	sum = area1 + area2;
	sum = sum + area3;
	// std::cout << "sum: " << sum.toFloat() << std::endl;
	if (origin_area == sum)
		return (true);
	return (false);
}
