#include "Fixed.hpp"
#include "Point.hpp"

Fixed	triangle_area(const Point& a, const Point& b, const Point& c)
{
	Fixed	area((a.get_x() * (b.get_y() - c.get_y()) +
				  b.get_x() * (c.get_y() - a.get_y()) +
				  c.get_x() * (a.get_y() - b.get_y())) / 2.0f);

	if (area < 0)
		return (area * -1);
	return (area);
}

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point)
{
	Fixed	A, A1, A2, A3;

	A = triangle_area(a, b, c);
	A1 = triangle_area(point, b, c);
	A2 = triangle_area(a, point, c);
	A3 = triangle_area(a, b, point);

	if (A1 == 0 || A2 == 0 || A3 == 0)
		return (false);
	return (A == (A1 + A2 + A3));
}
