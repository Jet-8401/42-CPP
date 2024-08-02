#include <iostream>
#include "Zombie.hpp"

Zombie::~Zombie(void)
{
	std::cout << "deleting " << this->name << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}
