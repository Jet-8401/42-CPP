#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

# include "Bureaucrat.hpp"
# include <ostream>
# include <string>
# include <exception>

# define EXCEPT_FORM_GRADE_TOO_LOW "Form grade is too low"
# define EXCEPT_FORM_GRADE_TOO_HIGH "Form grade is to high"

class Form {
	private:
		Form(void);

		bool				_is_signed;
		const std::string	_name;
		const unsigned int	_sign_grade_required;
		const unsigned int	_execute_grade_required;

	public:
		class	GradeTooHighException;
		class	GradeTooLowException;

		Form(Form& source);
		Form(std::string name, const unsigned int sign_grade_required,
			const unsigned int execute_grade_required);
		~Form(void);

		Form&	operator=(Form& rhs);

		const bool&			getSigned(void) const;
		const std::string&	getName(void) const;
		const unsigned int&	getSignGrade(void) const;
		const unsigned int& getExecuteGrade(void) const;
		void				beSigned(Bureaucrat& bureaucrat);
};

class Form::GradeTooHighException : public std::exception {
	const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception {
	const char* what() const throw();
};

std::ostream&	operator<<(std::ostream& out, const Form& rhs);

#endif
