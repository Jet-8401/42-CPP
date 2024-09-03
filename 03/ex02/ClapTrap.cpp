#include <iostream>
#include "ClapTrap.hpp"

// Constructor / Desctructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

ClapTrap::ClapTrap(void):
	_name("default"),
	_hit_pts(0),
	_energy_pts(0),
	_attack_dmg(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const std::string& name):
	_name(name),
	_hit_pts(10),
	_energy_pts(10),
	_attack_dmg(0)
{
	std::cout << "Constructor with name parameter called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	*this = rhs;

	std::cout << "Copy constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_energy_pts = rhs._energy_pts;
	this->_attack_dmg = rhs._attack_dmg;

	std::cout << "Copy assignment called" << std::endl;
	return (*this);
}

// Member function
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

/* Do action check wether an action can be performed
 * based onto the energy points, if it can't just print a message
 * and return false, else subtract the energy point by the cost of that action.
 * The message don't end to let any function continue that message !
 */
bool	ClapTrap::_do_action(unsigned int cost, const char *action)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "It might be hard for " << this->_name << ' '
			<< action << " as he is insied a graveyard (RIP)" << std::endl;
		return (0);
	}
	else if (this->_energy_pts == 0 || this->_energy_pts < cost)
	{
		std::cout << this->_name << " don't have enough energy points left "
			<< action << std::endl;
		return (0);
	}

	this->_energy_pts -= cost;
	return (1);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_do_action(1, "to attack..."))
		return ;

	std::cout << this->_name << " attacks " << target << ", causing "
		<< this->_attack_dmg << " points of damage!" << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int ammount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << this->_name << " have been attacked, but"
			<< " can't be deader than dead (not hit points left)" << std::endl;
		return ;
	}

	if (this->_hit_pts < ammount)
		this->_hit_pts = 0;
	else
		this->_hit_pts -= ammount;

	std::cout << this->_name << " have taken " << ammount
		<< " points of damage!";
	if (this->_hit_pts == 0)
		std::cout << " (causing permanent death)";
	else
		std::cout << ' ' << this->_hit_pts << " hit points remaining.";
	std::cout << std::endl;

	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_do_action(1, "to be repaired..."))
		return ;

	this->_hit_pts += amount;
	std::cout << this->_name << " has been repaired and now have "
		<< this->_hit_pts << " hit points!" << std::endl;
	return ;
}
