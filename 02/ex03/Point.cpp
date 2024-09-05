#include "Point.hpp"

// Constructor / Desctructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Point::Point(void):	_x(0), _y(0) {}

Point::~Point(void) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point& rhs): _x(rhs._x), _y(rhs._y) {}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Point&	Point::operator=(const Point& rhs)
{
	(void) rhs;
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

const Fixed&	Point::get_x(void) const
{
	return (this->_x);
}

const Fixed&	Point::get_y(void) const
{
	return (this->_y);
}
