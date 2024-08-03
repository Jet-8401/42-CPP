#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name): name(name) {};

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their "
		<< (this->weapon == 0 ? "nothing..." : this->weapon->getType())
		<< std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
