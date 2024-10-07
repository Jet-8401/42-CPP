#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try {
		Bureaucrat	John("John", 150);

		ShrubberyCreationForm	bery("home");
		John.signForm(bery);
		John.executeForm(bery);

		RobotomyRequestForm	robotForm("bob");
		John.signForm(robotForm);
		robotForm.execute(John);
		robotForm.execute(John);
		robotForm.execute(John);
		robotForm.execute(John);
		robotForm.execute(John);
		robotForm.execute(John);

		PresidentialPardonForm	form("45f");
		John.signForm(form);
		std::cout << John << std::endl;
		std::cout << form << std::endl;

		form.execute(John);
	}
	catch(std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
