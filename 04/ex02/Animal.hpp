#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	public:
		virtual	~Animal(void);

		Animal&	operator=(const Animal& rhs);

		virtual void		makeSound(void) const;
		const std::string&	getType(void) const;

	protected:
		Animal(void);
		Animal(const Animal& rhs);

		std::string	_type;
};

#endif
