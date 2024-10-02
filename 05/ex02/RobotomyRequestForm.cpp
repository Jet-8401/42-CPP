#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyRequestForm", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

RobotomyRequestForm&
	RobotomyRequestForm::operator=(RobotomyRequestForm& rhs)
{
	AForm::operator=(rhs);
	return (*this);
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	static bool fail = true;

	try {
		this->checkExecution(executor);
	} catch(...) {
		throw ;
	}

	std::cout << "**drilling noises**" << std::endl;
	if (fail)
		std::cout << this->getTarget() << " could not bee robotomized !"
			<<	std::endl;
	else
		std::cout << this->getTarget() << " has been robotomized !"
			<< std::endl;
	fail = !fail;
	return ;
}
