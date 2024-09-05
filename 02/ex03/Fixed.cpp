#include "Fixed.hpp"

#define SCALE (1 << Fixed::_fractbits)

short	Fixed::_fractbits = 8;

// Constructors
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __

Fixed::Fixed(void): _rawbits(0) {}

Fixed::Fixed(const Fixed & origin)
{
	*this = origin;
}

// Save the value by SCALE it up by bitshifting.
Fixed::Fixed(const int n)
{
	this->_rawbits = n << Fixed::_fractbits;
}

// Save the value by multiply the float value with the scale value to keep
// the fractional part into the integer.
Fixed::Fixed(const float f)
{
	this->_rawbits = f * (float)(SCALE) + (f >= 0 ? 0.5 : -0.5);
}

Fixed::~Fixed(void) {}

// Operator overloads
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __

Fixed &	Fixed::operator=(const Fixed& rhs)
{
	this->_rawbits = rhs._rawbits;
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed	copy;

	copy.setRawBits(this->_rawbits + rhs._rawbits);
	return (copy);
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed	copy;

	copy.setRawBits(this->_rawbits - rhs._rawbits);
	return (copy);
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed	copy;

	copy.setRawBits((int)
		((((long long) this->_rawbits) * ((long long) rhs._rawbits))
		>> (Fixed::_fractbits)));
	return (copy);
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed	copy;

	copy.setRawBits(((long long) this->_rawbits << Fixed::_fractbits)
		/ rhs._rawbits);
	return (copy);
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->_rawbits > rhs._rawbits);
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->_rawbits < rhs._rawbits);
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->_rawbits >= rhs._rawbits);
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->_rawbits <= rhs._rawbits);
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->_rawbits == rhs._rawbits);
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->_rawbits != rhs._rawbits);
}

Fixed&	Fixed::operator++(void)
{
	return (++this->_rawbits, *this);
}

Fixed&	Fixed::operator--(void)
{
	return (--this->_rawbits, *this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	copy = *this;
	return (++this->_rawbits, copy);
}

Fixed	Fixed::operator--(int)
{
	Fixed	copy = *this;
	return (--this->_rawbits, copy);
}

std::ostream &	operator<<(std::ostream & out, Fixed const & rhs)
{
	out << rhs.toFloat();
	return (out);
}

// Functions member
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __

int	Fixed::getRawBits(void) const
{
	return (this->_rawbits);
}

void	Fixed::setRawBits(int const raw)
{
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
