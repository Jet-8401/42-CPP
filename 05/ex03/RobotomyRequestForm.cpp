#include <iostream>
#include <cstdlib>
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
	static unsigned int seed_fluctuator = 0;
	static bool fail = 0;

	try {
		this->checkExecution(executor);
	} catch(...) {
		throw ;
	}

	srand((unsigned) time(NULL) + seed_fluctuator);
	seed_fluctuator += 200;
	fail = rand() % 2;

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
