#include "Bureaucrat.hpp"
#include "Form.hpp"

// Exceptions
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

const char*	AForm::GradeTooHighException::what() const throw()
{
	return (EXCEPT_FORM_GRADE_TOO_HIGH);
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return (EXCEPT_FORM_GRADE_TOO_LOW);
}

// Consctructors / Desctructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

AForm::AForm(void):
	_is_signed(false),
	_name("default"),
	_sign_grade_required(1),
	_execute_grade_required(1)
{}

AForm::AForm(AForm& source):
	_name(source.getName()),
	_sign_grade_required(source.getSignGrade()),
	_execute_grade_required(source.getExecuteGrade())
{
	*this = source;
	return ;
}

AForm::AForm(std::string name, const unsigned int sign_grade_required,
	const unsigned int execute_grade_required):
	_is_signed(false),
	_name(name),
	_sign_grade_required(sign_grade_required),
	_execute_grade_required(execute_grade_required)
{
	if (sign_grade_required < Bureaucrat::HighestGrade
		|| execute_grade_required < Bureaucrat::HighestGrade)
		throw AForm::GradeTooLowException();
	else if (sign_grade_required > Bureaucrat::LowestGrade
		|| execute_grade_required > Bureaucrat::LowestGrade)
		throw AForm::GradeTooHighException();
	return ;
}

AForm::~AForm(void) {}

// Operator overloads
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

AForm&	AForm::operator=(AForm& rhs)
{
	this->_is_signed = rhs._is_signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const AForm& rhs)
{
	out << rhs.getName() << "'s form information:\n"
		<< "\t-Is signed: [" << (rhs.getSigned() ? "yes]" : "false]") << '\n'
		<< "\t-Grade required to sign: [" << rhs.getSignGrade() << "]\n"
		<< "\t-Grade required to execute: [" << rhs.getExecuteGrade() << ']'
		<< std::endl;
	return (out);
}

// Function memebers
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

const bool&	AForm::getSigned(void) const
{
	return (this->_is_signed);
}

const std::string&	AForm::getName(void) const
{
	return (this->_name);
}

const unsigned int&	AForm::getSignGrade(void) const
{
	return (this->_sign_grade_required);
}

const unsigned int&	AForm::getExecuteGrade(void) const
{
	return (this->_execute_grade_required);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_sign_grade_required)
		this->_is_signed = true;
	else
		throw AForm::GradeTooLowException();
	return ;
}
