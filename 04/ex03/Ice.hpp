#pragma once

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
	protected:
		Ice&	operator=(const Ice& rhs);
	public:
		Ice(void);
		Ice(const Ice& rhs);
		~Ice(void);


		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
