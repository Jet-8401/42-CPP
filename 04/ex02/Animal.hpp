#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class A_Animal {
	public:
		virtual	~A_Animal(void);

		A_Animal&	operator=(const A_Animal& rhs);

		virtual void		makeSound(void) const = 0;
		const std::string&	getType(void) const;

	protected:
		A_Animal(void);
		A_Animal(const A_Animal& rhs);

		std::string	_type;
};

#endif
