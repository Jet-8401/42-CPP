#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include "Brain.hpp"
# include "Animal.hpp"

class Cat : public A_Animal {
	public:
		Cat(void);
		Cat(const Cat& rhs);
		~Cat(void);

		Cat&	operator=(const Cat& rhs);

		void	makeSound(void) const;
	private:
		Brain*	_brain;
};

#endif
