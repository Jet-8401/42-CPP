#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// Constructor / Desctructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

ScavTrap::ScavTrap(void): ClapTrap(), _keeper_mode(0)
{
	this->_announce();
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name), _keeper_mode(0)
{
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;

	this->_announce();
	std::cout << "String constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& rhs): ClapTrap(rhs)
{
	*this = rhs;

	this->_announce();
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	this->_announce();
	std::cout << "Default destructor called" << std::endl;
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_attack_dmg = rhs._attack_dmg;
	this->_energy_pts = rhs._energy_pts;
	this->_keeper_mode = rhs._keeper_mode;

	return (*this);
}

// Member function
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	ScavTrap::_announce(void)
{
	std::cout << "\x1B[35m[ ScapTrap ] \x1b[0m";
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
	this->_announce();

	this->ClapTrap::attack(target);
	return ;
}

void	ScavTrap::guardGate(void)
{
	this->_announce();

	if (this->_keeper_mode)
	{
		std::cout << this->_name << " is already in \"Gate keeper mode\""
			<< std::endl;
		return ;
	}
	this->_keeper_mode = 1;

	std::cout << this->_name << " is now in \"Gate keeper mode\"!" << std::endl;
	return ;
}
