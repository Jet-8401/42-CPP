#include "Point.hpp"

Point::Point(void):	_x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point & origin)
{
	*this = origin;
}

Point &	Point::operator=(const Point & rhs)
{
	(void) rhs;
	return (*this);
}

Point::~Point(void) {}
