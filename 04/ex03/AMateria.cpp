#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

AMateria::AMateria(void): AMateria("ice")
{
	return ;
}

AMateria::AMateria(const AMateria& rhs)
{
	*this = rhs;
}

AMateria::~AMateria(void)
{
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	this->_type = rhs.getType();
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

const std::string&	AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	return ;
}
