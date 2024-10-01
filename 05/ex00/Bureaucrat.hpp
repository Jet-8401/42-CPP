#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <ostream>
# include <string>

# define EXCEPT_GRADE_HIGH "Grade too hight, cannot be higher than 1"
# define EXCEPT_GRADE_LOW "Grade too low, cannot be lower than 150"

class Bureaucrat {
	private:
		Bureaucrat(void);
		void	_checkGrade(const unsigned int& grade) const;

		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat(Bureaucrat& source);
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat(void);

		Bureaucrat&	operator=(Bureaucrat& rhs);

		const std::string&	getName(void) const;
		const unsigned int&	getGrade(void) const;
		Bureaucrat&			incrementGrade(void);
		Bureaucrat&			decrementGrade(void);

		class	GradeTooHighException;
		class	GradeTooLowException;

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
