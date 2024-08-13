#include <iostream>
#include "Fixed.hpp"

short	Fixed::_bits = 8;

Fixed::Fixed(void): mantissa(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(const Fixed & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->mantissa = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->mantissa);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->mantissa = raw;
}
