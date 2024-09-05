#include "Fixed.hpp"
#include "Point.hpp"

Fixed	abs(Fixed value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

Fixed	calculate_area(const Point& a, const Point& b, const Point& c)
{
	return (
		(a.get_x() * (b.get_y()-c.get_y()) +
		b.get_x() * (c.get_y()-a.get_y()) +
		c.get_x() * (a.get_y()-b.get_y()))
		/ 2
	);
}

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point)
{
	Fixed	A, A1, A2, A3;

	A = abs(calculate_area(a, b, c));
	A1 = abs(calculate_area(point, a, b));
	A2 = abs(calculate_area(point, b, c));
	A3 = abs(calculate_area(point, c, b));

	return (A == A1 + A2 + A3);
}
