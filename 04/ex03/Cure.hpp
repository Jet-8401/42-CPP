#pragma once

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	protected:
		Cure&	operator=(const Cure& rhs);
	public:
		Cure(void);
		Cure(const Cure& rhs);
		~Cure(void);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
