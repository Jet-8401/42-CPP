#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
//# include <exception>

class Intern {
	private:
		Intern(const Intern& src);

		Intern&	operator=(const Intern& rhs);

	public:
		// class UnexpectedFormName;

		Intern(void);
		virtual ~Intern(void);

		AForm*	makeForm(const std::string& name,
			const std::string& target) const;
};

/*
class Intern::UnexpectedFormName : public std::exception {
	const char* what(void) const throw();
};
*/

#endif
