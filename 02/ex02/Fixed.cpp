#include <iostream>
#include "Fixed.hpp"

#define SCALE (1 << Fixed::_fractbits)

#define DEFINE_OPERATOR(op) \
	bool Fixed::operator op(const Fixed & rhs) const { \
		return (this->_rawbits op rhs._rawbits); \
	}

#define PREFIX_OPERATOR(op) \
	float	Fixed::operator op(void) { \
		return (op this->_rawbits, this->toFloat()); \
	}

#define POSTFIX_OPERATOR(op) \
	float Fixed::operator op(int) { \
		Fixed	copy = *this; \
		return (op this->_rawbits, copy.toFloat()); \
	}

short	Fixed::_fractbits = 8;

// Constructors
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __

Fixed::Fixed(void): _rawbits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

// Save the value by SCALE it up by bitshifting.
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
	this->_rawbits = f * (float)(SCALE) + (f >= 0 ? 0.5 : -0.5);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Operator overloads
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __

Fixed &	Fixed::operator=(const Fixed & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawbits = rhs._rawbits;
	return (*this);
}

float Fixed::operator+(const Fixed & rhs) const
{
	return ((float)(this->_rawbits + rhs._rawbits) / SCALE);
}

float Fixed::operator-(const Fixed & rhs) const
{
	return ((float)(this->_rawbits - rhs._rawbits) / SCALE);
}

float Fixed::operator*(const Fixed & rhs) const
{
	return ((float)(((long long)this->_rawbits * (long long)rhs._rawbits)
		>> Fixed::_fractbits) / SCALE);
}

float Fixed::operator/(const Fixed & rhs) const
{
	return (((float)(this->_rawbits << Fixed::_fractbits) / rhs._rawbits)
		/ SCALE);
}

DEFINE_OPERATOR(>);
DEFINE_OPERATOR(<);
DEFINE_OPERATOR(>=);
DEFINE_OPERATOR(<=);
DEFINE_OPERATOR(==);
DEFINE_OPERATOR(!=);
PREFIX_OPERATOR(--);
PREFIX_OPERATOR(++);
POSTFIX_OPERATOR(++);
POSTFIX_OPERATOR(--);

std::ostream &	operator<<(std::ostream & out, Fixed const & rhs)
{
	out << rhs.toFloat();
	return (out);
}

// Functions member
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __

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
	return ((float) this->_rawbits / SCALE);
}

// Just bitshifting the raw bits by the scale value
// to loose the fractional part.
int		Fixed::toInt(void) const
{
	return (this->_rawbits >> Fixed::_fractbits);
}

Fixed &	Fixed::min(Fixed & a, Fixed & b)
{
	return (a > b ? b : a);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	return (a > b ? b : a);
}

Fixed &	Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b ? a : b);
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b)
{
	return (a > b ? a : b);
}

// Ressources:
// https://www.youtube.com/watch?v=ZMsrZvBmQnU