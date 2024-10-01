#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class AForm;

# include "AForm.hpp"
# include <exception>
# include <ostream>
# include <string>

# define EXCEPT_GRADE_HIGH "Bureaucrat grade too hight, cannot be higher than 1"
# define EXCEPT_GRADE_LOW "Bureaucrat grade too low, cannot be lower than 150"

class Bureaucrat {
	private:
		Bureaucrat(void);

		const std::string	_name;
		unsigned int		_grade;

	public:
		class	GradeTooHighException;
		class	GradeTooLowException;

		Bureaucrat(Bureaucrat& source);
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat(void);

		Bureaucrat&	operator=(Bureaucrat& rhs);

		const std::string&	getName(void) const;
		const unsigned int&	getGrade(void) const;
		Bureaucrat&			incrementGrade(void);
		Bureaucrat&			decrementGrade(void);
		void				signForm(AForm& form);

		static void	checkGrade(const unsigned int& grade);

		static const unsigned int	HighestGrade;
		static const unsigned int	LowestGrade;
};

class Bureaucrat::GradeTooHighException : public std::exception {
	const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception {
	const char* what() const throw();
};

std::ostream&	operator<<(std::ostream& str, const Bureaucrat& rhs);

#endif
