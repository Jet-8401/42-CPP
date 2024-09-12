#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		const std::string	_type;

		// unused for now
		AMateria&	operator=(const AMateria& rhs);
	public:
		AMateria(void);
		AMateria(const AMateria& rhs);
		AMateria(const std::string& type);
		virtual ~AMateria(void);

		const std::string& getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);

};

#endif
