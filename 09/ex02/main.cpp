#include "PmergeMe.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

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

bool	compare(t_int_link& first, t_int_link& last)
{
	return (first.value < last.value);
}

int	main(int argc, char* argv[])
{
	std::vector<unsigned int>	parsed_numbers;

	if (argc < 3)
		return (std::cerr << ERR_USAGE << std::endl, 0);
	if (parse_args(argc, argv, parsed_numbers) == -1)
		return (0);

	/*std::cout << "Unsorted sequence: ";
	for (std::vector<unsigned int>::iterator it = parsed_numbers.begin(); it != parsed_numbers.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;*/

	p_list	list;
	for (std::vector<unsigned int>::iterator it = parsed_numbers.begin(); it != parsed_numbers.end(); it++) {
		t_int_link temp;

		temp.value = *it;
		list.push_back(temp);
	}

	/*for (p_list::iterator it = list.begin(); it != list.end(); it++) {
		std::cout << it->value << " => " << &(*it) << std::endl;
	}*/
	pmergeList(list);
	printList(list);

	std::cout << "is sorted ? " << (std::is_sorted(list.begin(), list.end(), compare) ? "yes": "no") << std::endl;

	return (0);
}
