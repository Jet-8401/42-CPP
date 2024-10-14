#include "Span.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		Span	spCopy = Span(sp);

		std::cout << spCopy.shortestSpan() << std::endl;
		std::cout << spCopy.longestSpan() << std::endl;

		// test leaks and deep copies
		Span	otherSpan = Span(2);
		for (int i = 0; i < 2; i++)
			otherSpan.addNumber(i);
		otherSpan = sp;

		std::cout << otherSpan.shortestSpan() << std::endl;
		std::cout << otherSpan.longestSpan() << std::endl;
	}

	{
		Span sp(10);
		std::vector<int> array;
		std::vector<int>::iterator it;

		for (int i = 0; i < 10; i++)
			array.push_back(i);
		it = array.begin();
		sp.addNumber(45);
		sp.addNumber(it, array.end() - 1);
		//sp.printInternalBuffer();
	}

	{
		Span sp(50000);
		std::vector<int> array;
		std::vector<int>::iterator it;

		unsigned int seed;
		for (int i = 0; i < 50000; i++)
		{
			seed = time(NULL) * i;
			srand(seed);
			array.push_back(rand() % 100000);
		}

		sp.addNumber(array.begin(), array.end());
		//sp.printInternalBuffer();

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		Span sp(5);

		sp.addNumber(1);
		sp.addNumber(4);
		sp.addNumber(-10000);
		sp.addNumber(2);
		sp.addNumber(10000);

		std::cout << "-- -- -- -- -- -- -- --" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		}
	return 0;
}
