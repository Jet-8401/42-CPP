#include "Bureaucrat.hpp"
#include <ostream>

// Statics declarations
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

const unsigned int	Bureaucrat::HighestGrade = 1;
const unsigned int	Bureaucrat::LowestGrade = 150;

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

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(1)
{}

Bureaucrat::Bureaucrat(Bureaucrat& source)
{
	*this = source;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade):
	_name(name), _grade(grade)
{
	this->_checkGrade(grade);
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

// Functions memeber
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	Bureaucrat::_checkGrade(const unsigned int& grade) const
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
		this->_checkGrade(this->_grade - 1);
	} catch (...) {
		throw ;
	}
	this->_grade--;
	return (*this);
}

Bureaucrat&	Bureaucrat::decrementGrade(void)
{
	try {
		this->_checkGrade(this->_grade + 1);
	} catch (...) {
		throw;
	}
	this->_grade++;
	return (*this);
}
