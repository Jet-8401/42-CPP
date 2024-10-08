#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define FORMS_N 3

AForm*	createPresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	createRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	createShruberryCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

// Exceptions
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

/*
const char* Intern::UnexpectedFormName::what(void) const throw()
{
	return ("Unexpected form name");
}
*/

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Intern::Intern(void)
{}

Intern::Intern(const Intern& src)
{
	(void) src;
	return ;
}

Intern::~Intern(void)
{}

// Operator overloads
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Intern&	Intern::operator=(const Intern& src)
{
	(void) src;
	return (*this);
}

// Function members
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

AForm*	Intern::makeForm(const std::string& name,
	const std::string& target) const
{
	static AForm* (*constructors[FORMS_N])(const std::string&) = {
		createPresidentialPardonForm, createShruberryCreationForm,
		createRobotomyRequestForm
	};
	static std::string forms[FORMS_N] = {PRESIDENTIAL_FORM_NAME,
		SHRUBERRY_FORM_NAME, ROBOTOMY_FORM_NAME};

	for (int i = 0; i < FORMS_N; i++)
	{
		if (name != forms[i])
			continue ;
		std::cout << "Intern creates " << name << std::endl;
		return (constructors[i](target));
	}
	std::cout << name << " is not a valid form name !" << std::endl;
	return ((AForm *) 0);
}
