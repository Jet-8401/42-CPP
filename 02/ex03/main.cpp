#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point A(0, 0);
	Point B(5, 5);
	Point C(5, 0);

	Point P(2, 2);

	bool result = bsp(A, B, C, P);

	std::cout << "A(x,y) : " << A.get_x() << ',' << A.get_y() << std::endl;
	std::cout << "B(x,y) : " << B.get_x() << ',' << B.get_y() << std::endl;
	std::cout << "C(x,y) : " << C.get_x() << ',' << C.get_y() << std::endl;

	std::cout << "P(x,y) : " << P.get_x() << ',' << P.get_y() << std::endl;

	std::cout << "P is " << (result ? "" : "not ") << "inside the triangle ABC"
		<< std::endl;
	return (0);
}
