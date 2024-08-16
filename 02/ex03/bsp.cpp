#include "Point.hpp"

float sign(Point p1, Point p2, Point p3)
{
    return ((p1._x - p3._x) * (p2._y - p3._y) -
    	(p2._x - p3._x) * (p1._y - p3._y));
}

bool	Point::bsp(const Point a, const Point b, const Point c,
	const Point point)
{
	float d1, d2, d3;
    bool negative, positive;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

    negative = (d1 < 0) || (d2 < 0) || (d3 < 0);
    positive = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return (!(negative && positive));
}
