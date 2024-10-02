#include <fstream>
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

const char*	ShrubberyCreationForm::CannotCreateFileException::what(void) const
	throw()
{
	return ("Cannot create file");
}

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs)
{
	AForm::operator=(rhs);
	return (*this);
}

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream	output;

	try {
		this->checkExecution(executor);
	} catch(...) {
		throw ;
	}
	output.open((this->getTarget() + "_shrubbery").c_str(),
		std::ostream::out | std::ostream::trunc);
	if (output.fail())
		throw ShrubberyCreationForm::CannotCreateFileException();
	output	<< "        _-_\n"
			<< "     /~~   ~~\\\n"
			<< "  /~~         ~~\\\n"
			<< " {               }\n"
			<< "  \\  _-     -_  /\n"
			<< "     ~  \\ /  ~\n"
			<< " _- -   | | _- _\n"
			<< "   _ -  | |   -_\n"
			<< "        / \\\n";
	output.close();
	return ;
}
