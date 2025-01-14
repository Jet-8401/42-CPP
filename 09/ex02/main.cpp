#include "PmergeMe.hpp"
#include <bits/types/struct_timeval.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <stdint.h>
#include <sys/time.h>

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
	p_vector::const_iterator	end;

	if (vector.size() >= max_elements)
		end = vector.begin() + max_elements;
	else
		end = vector.begin() + vector.size();

	for (p_vector::const_iterator it = vector.begin(); it != end; it++)
		std::cout << *it << ' ';
	std::cout << "[...]" << std::endl;
}

void	print_list(p_list& list, unsigned int max_elements)
{
	p_list::const_iterator	end = list.begin();

	std::advance(end, list.size() >= max_elements ? max_elements : list.size());
	for (p_list::const_iterator it = list.begin(); it != end; it++)
		std::cout << it->value << ' ';
	std::cout << "[...]" << std::endl;
}

uint64_t getTimeMilliSeconds(void)
{
	struct timeval	tv;
	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_infos(p_list& list, p_vector& vector)
{
	uint64_t	a1, a2;

	std::cout << "Time to process a range of " << list.size() << " elements with std::list : ";
	a1 = getTimeMilliSeconds();
	pmergeList(list);
	a2 = getTimeMilliSeconds();
	std::cout << a2 - a1 << " ms" << std::endl;
	print_list(list, MAX_ELEMENTS);

	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : ";
	a1 = getTimeMilliSeconds();
	vector = pmergeVector(vector);
	a2 = getTimeMilliSeconds();
	std::cout << a2 - a1 << " ms" << std::endl;
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
