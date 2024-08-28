#include "main.hpp"

bool	validate_extraction(void)
{
	if (!std::cin.fail())
		return (true);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (false);
}
