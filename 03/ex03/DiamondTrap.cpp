#include <string>
#include <iostream>
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// Constructor / Desctructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

DiamondTrap::DiamondTrap(void): ClapTrap()
{
	this->_announce();

	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 30;

	std::cout << "Default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const std::string& name):
	ClapTrap(name + "_clap_name"),
	_name(name)
{
	/*this->_hit_pts = this->FragTrap::_hit_pts;
	this->_energy_pts = this->ScavTrap::_energy_pts;
	this->_attack_dmg = this->FragTrap::_attack_dmg;*/

	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 30;

	this->_announce();
	std::cout << "Name constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs):
	ClapTrap(rhs.ClapTrap::_name),
	FragTrap(rhs),
	ScavTrap(rhs)
{
	*this = rhs;

	this->_announce();
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	this->_announce();
	std::cout << "Default destructor called" << std::endl;
	return ;
}

// Operator olverload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	this->_name = rhs._name;
	this->_hit_pts = rhs._hit_pts;
	this->_energy_pts = rhs._energy_pts;
	this->_attack_dmg = rhs._attack_dmg;
	this->_keeper_mode = rhs._keeper_mode;

	this->_announce();
	std::cout << "Assignment overload called" << std::endl;
	return (*this);
}

// Member Function
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	DiamondTrap::_announce(void)
{
	std::cout << "\x1B[33m[ DiamondTrap ] \x1b[0m\x1b[3m("
		+ this->_name + ") \x1b[23m";
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	this->_announce();
	std::cout << "DiamondTrap instance's name: " << this->_name << std::endl;
	this->_announce();
	std::cout << "ClapTrap instance's name: " << this->ClapTrap::_name << std::endl;
	return ;
}
