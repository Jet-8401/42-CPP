#include "PmergeMe.hpp"
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>

#define ERR_USAGE "usage: ./PmergeMe <number1> <number2> number3..."
#define ERR_NUMBER_FORMAT "Error: Unexpected input: only unsigned numbers are expected => "
#define ERR_NUMBER_TOO_BIG "Error: Numbers can't exceed maximum unsigned intergers => "
#define MAX_ELEMENTS 15

int	parse_args(int argc, char* argv[], p_list& list, p_vector& vector)
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
		// add to vector
		vector.push_back(static_cast<unsigned int>(n));

		// add to list
		t_int_link temp;
		temp.value = static_cast<unsigned int>(n);
		list.push_back(temp);
	}
	return (0);
}

bool	compare(t_int_link& first, t_int_link& last)
{
	return (first.value < last.value);
}

void print_vector(p_vector& vector, unsigned int max_elements)
{
	for (p_vector::const_iterator it = vector.begin(); it != vector.begin() + max_elements; it++)
		std::cout << *it << ' ';
	std::cout << "[...]" << std::endl;
}

void	print_list(p_list& list, unsigned int max_elements)
{
	p_list::const_iterator	end = list.begin();

	std::advance(end, max_elements);
	for (p_list::const_iterator it = list.begin(); it != end; it++)
		std::cout << it->value << ' ';
	std::cout << "[...]" << std::endl;
}

static void	print_infos(p_list& list, p_vector& vector)
{
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : ";
	clock_t start = clock();
	pmergeList(list);
	clock_t end = clock();
	double time_taken = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << time_taken << " ms" << std::endl;
	print_list(list, MAX_ELEMENTS);

	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : ";
	start = clock();
	vector = pmergeVector(vector);
	end = clock();
	time_taken = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << time_taken << " ms" << std::endl;
	print_vector(vector, MAX_ELEMENTS);
}

int	main(int argc, char* argv[])
{
	p_list		list;
	p_vector	vector;

	if (argc < 3)
		return (std::cerr << ERR_USAGE << std::endl, 0);
	if (parse_args(argc, argv, list, vector) == -1)
		return (0);

	std::cout << "Unsorted sequence: ";
	print_vector(vector, MAX_ELEMENTS);
	std::cout << std::endl;
	print_infos(list, vector);

	return (0);
}
