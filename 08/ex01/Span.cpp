#include "Span.hpp"
#include <cstring>

const char*	Span::NotEnoughNumbersException::what(void) const throw()
{
	return "Not enough number stored";
}

const char*	Span::LimitReachException::what(void) const throw()
{
	return "Limit of number added reach";
}

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Span::Span(const Span& src): _intern(NULL)
{
	*this = src;
	return ;
}

Span::Span(const uint N): _length(N), _current_index(0)
{
	this->_intern = new uint[this->_length];
	memset(this->_intern, 0, this->_length * sizeof(uint));
	return ;
}

Span::~Span(void)
{
	delete [] this->_intern;
	return ;
}

// Operator overloads
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Span&	Span::operator=(const Span& rhs)
{
	this->_length = rhs._length;
	this->_current_index = rhs._current_index;
	delete [] this->_intern;
	this->_intern = new uint[this->_length];
	memcpy(this->_intern, rhs._intern, this->_length * sizeof(uint));
	return (*this);
}

// Function members
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	Span::addNumber(const uint N)
{
	if (this->_current_index >= this->_length)
		throw Span::LimitReachException();
	this->_intern[this->_current_index++] = N;
	return ;
}

uint	Span::_checkSpan(void (*f)(long* current_distance, long* distance)) const
{
	long	distance = 0;
	long	current_distance = 0;

	if (this->_current_index <= 1)
		throw Span::NotEnoughNumbersException();
	for (uint i = 1; i < this->_length; i++)
	{
		current_distance = static_cast<long>(this->_intern[i]) - this->_intern[i - 1];
		f(&current_distance, &distance);
	}
	return (distance);
}

static void	checkLongest(long *current_distance, long* distance) {
	if (*current_distance > *distance)
		*distance = *current_distance;
}

static void	checkShortest(long *current_distance, long* distance) {
	if (*current_distance < *distance)
		*distance = *current_distance;
	if (*distance < 0)
		*distance = -*distance;
}

uint	Span::longestSpan(void) const
{
	return (this->_checkSpan(checkLongest));
}

uint	Span::shortestSpan(void) const
{
	return (this->_checkSpan(checkShortest));
}
