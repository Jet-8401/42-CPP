#include <iostream>
#include "whatever.hpp"

int	main(void)
{
	{
		int	a = 5;
		int b = 10;

		char h = 'h';
		char i = 'i';

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		swap<int>(a, b);

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		std::cout << ::max<int>(a, b) << std::endl;

		std::cout << ::max<char>(h, i) << std::endl;
		std::cout << ::min<char>(h, i) << std::endl;
	}

	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	return (0);
}
