#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

# include "Bureaucrat.hpp"
# include <ostream>
# include <string>
# include <exception>

# define EXCEPT_FORM_GRADE_TOO_LOW "Form grade is too low"
# define EXCEPT_FORM_GRADE_TOO_HIGH "Form grade is to high"

class AForm {
	private:
		AForm(void);

		bool				_is_signed;
		const std::string	_name;
		const unsigned int	_sign_grade_required;
		const unsigned int	_execute_grade_required;

	public:
		class	GradeTooHighException;
		class	GradeTooLowException;

		AForm(AForm& source);
		AForm(std::string name, const unsigned int sign_grade_required,
			const unsigned int execute_grade_required);
		virtual ~AForm(void);

		AForm&	operator=(AForm& rhs);

		const bool&			getSigned(void) const;
		const std::string&	getName(void) const;
		const unsigned int&	getSignGrade(void) const;
		const unsigned int& getExecuteGrade(void) const;
		void				beSigned(Bureaucrat& bureaucrat);
};

class AForm::GradeTooHighException : public std::exception {
	const char* what() const throw();
};

class AForm::GradeTooLowException : public std::exception {
	const char* what() const throw();
};

std::ostream&	operator<<(std::ostream& out, const AForm& rhs);

#endif
