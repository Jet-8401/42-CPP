#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

std::string const	Weapon::getType(void) const
{
	std::string const type = this->type;
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
