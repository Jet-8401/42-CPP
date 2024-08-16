#include <iostream>
#include "Point.hpp"

int	main(void)
{
	Point A(1, 1);
	Point B(5, 5);
	Point C(0, 0);

	Point p(10, 10);

	bool result = Point::bsp(A, B, C, p);

	std::cout << result << std::endl;
	return (0);
}
