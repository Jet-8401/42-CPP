#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	/*Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;*/

	Fixed a(0);

	std::cout << (float) (1 << 24) << std::endl;
	std::cout << a.toFloat() << std::endl;

	return (0);
}
