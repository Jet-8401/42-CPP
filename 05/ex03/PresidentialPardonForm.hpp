#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define PRESIDENTIAL_FORM_NAME "presidential pardon"

class PresidentialPardonForm : public AForm {
	private:
		PresidentialPardonForm(void);
		PresidentialPardonForm&	operator=(PresidentialPardonForm& rhs);

		std::string	_target;

	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(PresidentialPardonForm& form);
		~PresidentialPardonForm(void);

		const std::string&	getTarget(void) const;
		void				execute(const Bureaucrat& executor) const;
};

#endif
