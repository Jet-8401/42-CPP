#include "easyfind.hpp"
#include <list>
#include <vector>
#include <iostream>

int	main(void)
{
	std::list<int> container;
	for (int i = 0; i < 10; i++)
		container.push_back(i);

	std::list<int>::iterator	result = ::easyfind(container, 192);
	std::cout << *result << std::endl;

	std::vector<int> vecContainer;
	for (int i = 0; i < 200; i++)
		vecContainer.push_back(i);

	std::vector<int>::iterator vecResult = ::easyfind(vecContainer, 199);
	std::cout << *vecResult << std::endl;
	return (0);
}
