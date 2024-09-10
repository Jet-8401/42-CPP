#include <iostream>
#include "WrongCat.hpp"

// Constructor / Destructor
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

WrongCat::WrongCat(void): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat& rhs): WrongAnimal(rhs)
{
	*this = rhs;

	std::cout << "WrongCat copy constructor called" << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat default destructor" << std::endl;
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	this->_type = rhs._type;

	std::cout << "WrongCat assignment operator called" << std::endl;
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong Miaouw !!!" << std::endl;
	return ;
}
