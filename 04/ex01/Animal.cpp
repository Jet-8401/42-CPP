#include <iostream>
#include "Animal.hpp"

// Constructor / Destructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Animal::Animal(void): _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal& rhs)
{
	*this = rhs;

	std::cout << "Animal copy constructor called" << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal default destructor" << std::endl;
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Animal&	Animal::operator=(const Animal& rhs)
{
	this->_type = rhs._type;

	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	Animal::makeSound(void) const
{
	std::cout << "*Animal sound.mp3*" << std::endl;
	return ;
}

const std::string&	Animal::getType(void) const
{
	return (this->_type);
}
