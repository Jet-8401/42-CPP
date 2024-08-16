#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	/*
	const Fixed a( 30.265f );
	const Fixed b( 2.4854f );
	Fixed		c;

	std::cout << a / b << std::endl;
	std::cout << "is 'a'(" << a << ") greater than 'b'(" << b << ") ? "
		<< (a > b ? "yes" : "non") << std::endl;

	std::cout << "min:" << Fixed::min(b, a) << std::endl;
	std::cout << "max:" << Fixed::max(a, b) << std::endl;
	std::cout << "max(a, a):" << Fixed::max(a, a) << std::endl;*/

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}
