#include "PmergeMe.hpp"
#include <cstring>
#include <iostream>
#include <limits>
#include <list>
#include <sstream>
#include <vector>
// note: map and stack are not allowed !

#define ERR_USAGE "usage: ./PmergeMe <number1> <number2> number3..."
#define ERR_NUMBER_FORMAT "Error: Unexpected input: only unsigned numbers are expected => "
#define ERR_NUMBER_TOO_BIG "Error: Numbers can't exceed maximum unsigned intergers => "

int	parse_args(int argc, char* argv[], std::vector<unsigned int>& container)
{
	long	n = 0;

	for (int i = 1; i < argc; i++) {
		std::stringstream ss;
		ss << argv[i];
		ss >> n;
		if (n > std::numeric_limits<unsigned int>::max())
			return (std::cerr << ERR_NUMBER_TOO_BIG << argv[i] << std::endl, -1);
		if (ss.fail() || !ss.eof() || n < 0)
			return (std::cerr << ERR_NUMBER_FORMAT << argv[i] << std::endl, -1);
		container.push_back(static_cast<unsigned int>(n));
	}
	return (0);
}

int	main(int argc, char* argv[])
{
	std::vector<unsigned int>	parsed_numbers;

	if (argc < 3)
		return (std::cerr << ERR_USAGE << std::endl, 0);
	if (parse_args(argc, argv, parsed_numbers) == -1)
		return (0);

	std::cout << "Unsorted sequence: ";
	for (std::vector<unsigned int>::iterator it = parsed_numbers.begin(); it != parsed_numbers.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	p_list	list(parsed_numbers.begin(), parsed_numbers.end());
	pmerge_list(list);

	return (0);
}
