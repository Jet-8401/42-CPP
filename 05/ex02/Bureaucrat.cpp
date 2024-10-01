#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <iostream>

// Static declarations
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

const unsigned int Bureaucrat::HighestGrade = 1;
const unsigned int Bureaucrat::LowestGrade = 150;

// Exceptions
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (EXCEPT_GRADE_HIGH);
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (EXCEPT_GRADE_LOW);
}

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{}

Bureaucrat::Bureaucrat(Bureaucrat& source)
{
	*this = source;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade):
	_name(name), _grade(grade)
{
	Bureaucrat::checkGrade(grade);
	return ;
}

Bureaucrat::~Bureaucrat(void)
{}

// Opertor overloads
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Bureaucrat&	Bureaucrat::operator=(Bureaucrat& rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '.';
	return (out);
}

// Functions member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	Bureaucrat::checkGrade(const unsigned int& grade)
{
	if (grade < Bureaucrat::HighestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::LowestGrade)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

const unsigned int&	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

Bureaucrat&	Bureaucrat::incrementGrade(void)
{
	try {
		Bureaucrat::checkGrade(this->_grade - 1);
	} catch (...) {
		throw ;
	}
	this->_grade--;
	return (*this);
}

Bureaucrat&	Bureaucrat::decrementGrade(void)
{
	try {
		Bureaucrat::checkGrade(this->_grade + 1);
	} catch (...) {
		throw;
	}
	this->_grade++;
	return (*this);
}

void	Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << this->_name << " couldn't sign form " << form.getName()
			<< " with reason of: \"" << e.what() << "\"." << std::endl;
		return ;
	}
	std::cout << this->_name << " signed form " << form.getName() << " !"
		<< std::endl;
	return ;
}
