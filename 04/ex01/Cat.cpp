#include <iostream>
#include "Cat.hpp"

// Constructor / Destructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Cat::Cat(void): Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat& rhs): Animal(rhs)
{
	*this = rhs;

	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor" << std::endl;
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Cat&	Cat::operator=(const Cat& rhs)
{
	this->_type = rhs._type;

	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	Cat::makeSound(void) const
{
	std::cout << "Miaouw !!!" << std::endl;
	return ;
}
