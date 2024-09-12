#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"

// Constructor / Destructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Dog::Dog(void): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
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
	delete this->_brain;
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Dog&	Dog::operator=(const Dog& rhs)
{
	this->_type = rhs._type;
	*this->_brain = *rhs._brain;

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
