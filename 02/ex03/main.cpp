#include <iostream>
#include "Point.hpp"

int	main(void)
{
	Point A(0, 0);
	Point B(5, 5);
	Point C(5, 0);

	Point p(-6,-6);

	Fixed b(5);
	Fixed a(2);
	std::cout << (a / b).toFloat() << std::endl;

	bool result = bsp(A, B, C, p);

	std::cout << result << std::endl;
	return (0);
}
