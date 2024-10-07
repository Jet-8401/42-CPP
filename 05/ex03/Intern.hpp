#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
	private:
		Intern&	operator=(const Intern& rhs);

		static AForm* forms[3];

	public:
		Intern(void);
		Intern(const Intern& src);
		virtual ~Intern(void);

		AForm&	makeForm(const std::string& name,
			const std::string& target) const;
};

#endif
