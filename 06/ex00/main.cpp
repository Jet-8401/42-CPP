#include <iostream>
#include "ScalarConverter.hpp"

#define ERR_USAGE "usage: convert <element to convert>"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (std::cout << ERR_USAGE << std::endl, 0);
	ScalarConverter::convert(argv[1]);
	return (0);
}
