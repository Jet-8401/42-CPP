#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	public:
		Animal(void);
		Animal(const Animal& rhs);
		virtual	~Animal(void);

		Animal&	operator=(const Animal& rhs);

		virtual void		makeSound(void) const;
		const std::string&	getType(void) const;

	protected:
		std::string	_type;
};

#endif
