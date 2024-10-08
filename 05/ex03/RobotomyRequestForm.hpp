#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# define ROBOTOMY_FORM_NAME "robotomy request"

class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(RobotomyRequestForm& rhs);

		std::string	_target;

	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(RobotomyRequestForm& form);
		~RobotomyRequestForm(void);

		const std::string&	getTarget(void) const;
		void				execute(const Bureaucrat& executor) const;
};

#endif
