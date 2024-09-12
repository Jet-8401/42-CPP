#include <cstring>
#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Character::Character(void)
{
	memset(this->_inv, 0, sizeof(this->_inv));

	return ;
}

Character::Character(const Character& rhs)
{
	memset(this->_inv, 0, sizeof(this->_inv));
	*this = rhs;
	return ;
}

Character::Character(const std::string& name): _name(name)
{
	memset(this->_inv, 0, sizeof(this->_inv));

	return ;
}

Character::~Character(void)
{
	for (int slot = 0; slot < INVENTORY_SLOTS; slot++)
	{
		delete this->_inv[slot];
		this->_inv[slot] = NULL;
	}
	return ;
}

// Overload operator
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Character&	Character::operator=(const Character& rhs)
{
	this->_name = rhs.getName();
	for (int slot = 0; slot < INVENTORY_SLOTS; slot++)
	{
		if (this->_inv[slot])
			delete this->_inv[slot];
		if (rhs._inv[slot])
			this->_inv[slot] = rhs._inv[slot]->clone();
	}
	return (*this);
}

// Function memeber
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

AMateria**	Character::_findEmptySlot(void)
{
	for (int slot = 0; slot < INVENTORY_SLOTS; slot++)
		if (!this->_inv[slot])
			return (&this->_inv[slot]);
	return (NULL);
}

AMateria*	Character::getInvSlot(int idx)
{
	if (idx >= INVENTORY_SLOTS || idx < 0)
		return (NULL);
	return (this->_inv[idx]);
}

const std::string&	Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria* materia)
{
	AMateria**	tmp;

	tmp = this->_findEmptySlot();
	if (!materia || !tmp)
		return ;
	*tmp = materia;
	return ;
}

void	Character::unequip(int idx)
{
	if (idx >= INVENTORY_SLOTS || idx < 0)
		return ;
	this->_inv[idx] = NULL;
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	AMateria*	materia;

	materia = this->getInvSlot(idx);
	if (!materia)
	{
		std::cout << this->_name << " cannot use materia[" << idx << "] on "
			<< target.getName() << std::endl;
		return ;
	}
	materia->use(target);
	return ;
}
