#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm& rhs);

		std::string	_target;

	public:
		class CannotCreateFileException;

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm& form);
		~ShrubberyCreationForm(void);

		const std::string&	getTarget(void) const;
		void				execute(const Bureaucrat& executor) const;
};

class ShrubberyCreationForm::CannotCreateFileException : public std::exception {
	const char* what() const throw();
};

#endif
