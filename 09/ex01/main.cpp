#include "RPN.hpp"
#include <iostream>

#define ERR_USAGE "usage: ./RPN <expression>"

int	main(int argc, char* argv[])
{
	if (argc != 2)
		return (std::cerr << ERR_USAGE << std::endl, 0);
	evaluate_expr(argv[1]);
	return (0);
}
