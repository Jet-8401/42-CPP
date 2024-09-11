#include <iostream>
#include "Animal.hpp"

// Constructor / Destructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

A_Animal::A_Animal(void): _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

A_Animal::A_Animal(const A_Animal& rhs)
{
	*this = rhs;

	std::cout << "Animal copy constructor called" << std::endl;
	return ;
}

A_Animal::~A_Animal(void)
{
	std::cout << "Animal default destructor" << std::endl;
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

A_Animal&	A_Animal::operator=(const A_Animal& rhs)
{
	this->_type = rhs._type;

	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

const std::string&	A_Animal::getType(void) const
{
	return (this->_type);
}
