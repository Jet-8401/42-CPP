#include "Span.hpp"
#include <iostream>
#include <list>

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
		Span			sp(10);
		std::vector<int>	list;
		std::vector<int>::iterator it;

		for (int i = 0; i < 10; i++)
			list.push_back(i);
		it = list.begin();
		std::advance(it, 2);
		sp.addNUmber(list.begin(), list.end());
	}
	return 0;
}
