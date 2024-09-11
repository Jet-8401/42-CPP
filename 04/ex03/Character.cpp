#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

#include <iostream>

Character::Character(void)
{
	// test purposes
	for(int i = 0; i < INVENTORY_SLOTS; i++)
		std::cout << this->_inv[i] << std::endl;
	return ;
}

Character::Character(const Character& rhs)
{
	*this = rhs;
	return ;
}

Character::Character(const std::string& name): _name(name)
{
	return ;
}

Character::~Character(void)
{
	return ;
}

// Overload operator
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Character&	Character::operator=(const Character& rhs)
{

}

// Function memeber
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

AMateria*	Character::_findEmptySlot(void)
{
	for (int slot = 0; slot < INVENTORY_SLOTS; slot++)
		if (!this->_inv[slot])
			return (this->_inv[slot]);
	return (NULL);
}

const std::string&	Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria* materia)
{
	AMateria*	empy_slot = this->_findEmptySlot();
	empy_slot = materia;
	return ;
}

void	Character::unequip(int idx)
{
	if (idx >= INVENTORY_SLOTS || idx < 0)
		return ;
	this->_inv[idx] = NULL;
	return ;
}

void	Character::use(int idx, ICharacter& target) const
{
	const AMateria*	materia;
	materia = this->getInvSlot(idx);
	if (!materia)
		return ;
	materia->use(target);
	return ;
}
