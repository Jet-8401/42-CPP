#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try {
		Bureaucrat	John("John", 28);
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (!rrf)
		{
			std::cout << "rrf is NULL" << std::endl;
			return (0);
		}
		std::cout << *rrf << std::endl;
		//rrf->execute(John);
		rrf->beSigned(John);
		rrf->execute(John);
		std::cout << *rrf << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
