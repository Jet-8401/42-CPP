#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresidentialPardonForm", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

PresidentialPardonForm&
	PresidentialPardonForm::operator=(PresidentialPardonForm& rhs)
{
	AForm::operator=(rhs);
	return (*this);
}

const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	try {
		this->checkExecution(executor);
	} catch(...) {
		throw ;
	}
	std::cout << this->getTarget()
		<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}