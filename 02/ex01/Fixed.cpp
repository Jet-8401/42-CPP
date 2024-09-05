#include <iostream>
#include "Fixed.hpp"

short	Fixed::_fractbits = 8;

// Constructors

Fixed::Fixed(void): _rawbits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

// Save the value and clear the fractional part by bitshift it to the left.
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawbits = n << Fixed::_fractbits;
}

// Save the value by multiply the float value with the scale value to keep
// the fractional part into the integer.
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawbits = f * float(1 << Fixed::_fractbits) + (f >= 0 ? 0.5 : -0.5);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Operator overloads

Fixed &	Fixed::operator=(const Fixed & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawbits = rhs._rawbits;
	return (*this);
}

std::ostream &	operator<<(std::ostream & out, Fixed const & rhs)
{
	out << rhs.toFloat();
	return (out);
}

// Functions member

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawbits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawbits = raw;
}

// Divide the raw bits by the scale value and cast it into a float
// to keep the fractional part.
float	Fixed::toFloat(void) const
{
	return ((float) this->_rawbits / (1 << Fixed::_fractbits));
}

// Just bitshifting the raw bits by the scale value
// to loose the fractional part.
int		Fixed::toInt(void) const
{
	return (this->_rawbits >> Fixed::_fractbits);
}

// Ressources:
// https://www.youtube.com/watch?v=ZMsrZvBmQnU
