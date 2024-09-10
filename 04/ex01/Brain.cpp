#include <iostream>
#include "Brain.hpp"

// Constructors / Desctructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain& rhs)
{
	*this = rhs;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain default desctructor called" << std::endl;
	return ;
}

// Operator overloads
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Brain&	Brain::operator=(const Brain& rhs)
{
	for (int i = 0; i < IDEAS_N; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}
