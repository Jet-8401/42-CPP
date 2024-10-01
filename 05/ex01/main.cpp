#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat	John("John", 149);
		AForm	someStuff("42b", 100, 150);

		std::cout << someStuff << std::endl;

		std::cout << John << std::endl;
		John.decrementGrade();
		for (int i = 0; i < 49; i++) {
			std::cout << John << std::endl;
			John.incrementGrade();
		}
		std::cout << John << std::endl;

		John.signForm(someStuff);
		std::cout << someStuff << std::endl;
		John.incrementGrade();
		std::cout << John << std::endl;
		John.signForm(someStuff);
		std::cout << someStuff << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
