#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point A(0, 0);
	Point B(5, 5);
	Point C(5, 0);

	Point p(1, 1);

	int result = bsp(A, B, C, p);
	std::cout << A.get_x() << "*(" << B.get_y() << '-' << C.get_y() << ")" << std::endl;
	std::cout << A.get_x() * (B.get_y()-C.get_y()) << std::endl;

	std::cout << "result: " << result << std::endl;

	/*
	std::cout << Fixed(5).toFloat() << std::endl;
	std::cout << Fixed(3) * Fixed(5.5f) << std::endl;
	std::cout << (Fixed(4) + Fixed(4) * Fixed(2)) / Fixed(2) << std::endl;
	std::cout << Fixed(50) / Fixed(3) << std::endl;
	std::cout << --Fixed(0) + ++Fixed(0) << std::endl;
	std::cout << ++Fixed(0)++ << std::endl;
	std::cout << Fixed(6548.5555555555556f) / Fixed(100000) << std::endl;
	*/
	return (0);
}
