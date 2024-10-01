#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	*John;

	try {
		John = new Bureaucrat("John", 149);
		std::cout << *John << std::endl;
		John->decrementGrade();
		// Decomment will throw an exception, therefore stopping the loop
		//std::cout << *John << std::endl;
		//John->decrementGrade();
		for (int i = 0; i < 40; i++) {
			std::cout << *John << std::endl;
			John->incrementGrade();
		}
		std::cout << *John << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	std::cout << *John << std::endl;
	delete John;
	return (0);
}
