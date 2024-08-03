#include "Harl.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc != 2)
		return (std::cerr << "\x1B[31mUsage: ./harlFilter \"level\"\x1B[0m\n",
			0);
	harl.complain(argv[1]);
	return (0);
}
