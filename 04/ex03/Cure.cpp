#include <iostream>
#include "Cure.hpp"
#include "AMateria.hpp"

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Cure::Cure(void): AMateria("cure")
{
	return ;
}

Cure::Cure(const Cure& rhs): AMateria(rhs)
{
	*this = rhs;
}

Cure::~Cure(void)
{
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Cure&	Cure::operator=(const Cure& rhs)
{
	AMateria::operator=(rhs);
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

AMateria*	Cure::clone(void) const
{
	AMateria*	cloned = new Cure(*this);
	return (cloned);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return ;
}
