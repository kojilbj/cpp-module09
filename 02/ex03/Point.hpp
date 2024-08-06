#ifndef POINT_HPP
#define POINT_HPP

#include "./Fixed.hpp"

class	Point
{
	public:
		Point(void);
		Point(float x, float y);
		Point(const Point& point);
		~Point(void);

		Point&	operator=(const Point& point);

		float	get_x(void) const;
		float	get_y(void) const;
	private:
		const Fixed	x_;
		const Fixed	y_;
};

#endif