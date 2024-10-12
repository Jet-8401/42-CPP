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

Span::Span(const Span& src)
{
	this->_internal_vector = new std::vector<int>(src._internal_vector->size(), 0);
	*this = src;
	return ;
}

Span::Span(const uint N): _initialized_elements(0)
{
	this->_internal_vector = new std::vector<int>(N, 0);
	return ;
}

Span::~Span(void)
{
	delete this->_internal_vector;
	return ;
}

// Operator overloads
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Span&	Span::operator=(const Span& rhs)
{
	// the lign below can maybe cause some leaks: have to check execution
	*(this->_internal_vector) = *(rhs._internal_vector);
	this->_initialized_elements = rhs._initialized_elements;
	return (*this);
}

// Function members
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

uint	Span::_checkSpan(void (*f)(int* current_distance, int* prev_distance)) const
{
	std::vector<int>::const_iterator	it;
	int	prev_distance = 0;
	int	current_distance = 0;

	if (this->_initialized_elements <= 1)
		throw Span::NotEnoughNumbersException();
	for (it = ++(this->_internal_vector->begin()); it != this->_internal_vector->end(); it++)
	{
		current_distance = *it - *(it - 1);
		f(&current_distance, &prev_distance);
	}
	return (prev_distance);
}

void	Span::addNumber(const int value)
{
	if (this->_initialized_elements >= this->_internal_vector->size())
		throw Span::LimitReachException();
	(*this->_internal_vector)[this->_initialized_elements++] = value;
	return ;
}

static void	checkLongest(int *current_distance, int* prev_distance) {
	if (*current_distance > *prev_distance)
		*prev_distance = *current_distance;
}

static void	checkShortest(int *current_distance, int* prev_distance) {
	if (*current_distance < *prev_distance)
		*prev_distance = *current_distance;
	if (*prev_distance < 0)
		*prev_distance = -*prev_distance;
}

uint	Span::longestSpan(void) const
{
	return (this->_checkSpan(checkLongest));
}

uint	Span::shortestSpan(void) const
{
	return (this->_checkSpan(checkShortest));
}
