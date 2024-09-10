#include <iostream>
#include "WrongAnimal.hpp"

// Constructor / Destructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
{
	*this = rhs;

	std::cout << "WrongAnimal copy constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal default destructor" << std::endl;
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	this->_type = rhs._type;

	std::cout << "WrongAnimal assignment operator called" << std::endl;
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*WrongAnimal sound*" << std::endl;
	return ;
}

const std::string&	WrongAnimal::getType(void) const
{
	return (this->_type);
}
