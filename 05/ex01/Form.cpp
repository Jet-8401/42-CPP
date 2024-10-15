#include "Bureaucrat.hpp"
#include "Form.hpp"

// Exceptions
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

const char*	Form::GradeTooHighException::what() const throw()
{
	return (EXCEPT_FORM_GRADE_TOO_HIGH);
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return (EXCEPT_FORM_GRADE_TOO_LOW);
}

// Consctructors / Desctructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Form::Form(void):
	_is_signed(false),
	_name("default"),
	_sign_grade_required(1),
	_execute_grade_required(1)
{}

Form::Form(Form& source):
	_name(source.getName()),
	_sign_grade_required(source.getSignGrade()),
	_execute_grade_required(source.getExecuteGrade())
{
	*this = source;
	return ;
}

Form::Form(std::string name, const unsigned int sign_grade_required,
	const unsigned int execute_grade_required):
	_is_signed(false),
	_name(name),
	_sign_grade_required(sign_grade_required),
	_execute_grade_required(execute_grade_required)
{
	if (sign_grade_required < Bureaucrat::HighestGrade
		|| execute_grade_required < Bureaucrat::HighestGrade)
		throw Form::GradeTooLowException();
	else if (sign_grade_required > Bureaucrat::LowestGrade
		|| execute_grade_required > Bureaucrat::LowestGrade)
		throw Form::GradeTooHighException();
	return ;
}

Form::~Form(void) {}

// Operator overloads
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Form&	Form::operator=(Form& rhs)
{
	this->_is_signed = rhs._is_signed;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Form& rhs)
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

const bool&	Form::getSigned(void) const
{
	return (this->_is_signed);
}

const std::string&	Form::getName(void) const
{
	return (this->_name);
}

const unsigned int&	Form::getSignGrade(void) const
{
	return (this->_sign_grade_required);
}

const unsigned int&	Form::getExecuteGrade(void) const
{
	return (this->_execute_grade_required);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_sign_grade_required)
		this->_is_signed = true;
	else
		throw Form::GradeTooLowException();
	return ;
}
