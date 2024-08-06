#include "./Point.hpp"
#include "./Fixed.hpp"

Point::Point(void): x_(0), y_(0)
{

}

Point::Point(float x, float y): x_(x), y_(y)
{

}

Point::Point(const Point& point): x_(point.x_), y_(point.y_)
{
}

Point::~Point(void)
{

}

Point&	Point::operator=(const Point& point)
{
	if (this == &point)
		return (*this);
	return (*this);
}

float	Point::get_x(void) const
{
	return (this->x_.toFloat());
}

float	Point::get_y(void) const
{
	return (this->y_.toFloat());
}