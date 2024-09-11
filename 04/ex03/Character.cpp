#include "Character.hpp"

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Character::Character(void): _name("\0")
{
	// maybe init the inv pointers to NULL
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
