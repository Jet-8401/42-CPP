#include <iostream>
#include "whatever.hpp"

int	main(void)
{
	int	a = 5;
	int b = 10;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	swap(&a, &b);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	return (0);
}
