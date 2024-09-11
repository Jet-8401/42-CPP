#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		AMateria(void);
		AMateria(const AMateria& rhs);

		static const std::string	_type;

	public:
		virtual ~AMateria(void);
		AMateria(std::string const & type);

		const std::string& getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);

		AMateria&	operator=(const AMateria& rhs);
};

#endif
