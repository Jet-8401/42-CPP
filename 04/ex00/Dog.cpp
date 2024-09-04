#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"

// Constructor / Destructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Dog::Dog(void): Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog& rhs): Animal(rhs)
{
	*this = rhs;

	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog default destructor" << std::endl;
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Dog&	Dog::operator=(const Dog& rhs)
{
	this->_type = rhs._type;

	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	Dog::makeSound(void) const
{
	std::cout << "Waaaouf !!!" << std::endl;
	return ;
}
