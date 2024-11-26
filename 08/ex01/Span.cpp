#include "Span.hpp"
#include <cstring>
#include <limits>
//#include <iostream>

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

int	Span::_checkSpan(int min_base_value, void (*f)(int* current_distance, int* min_distance)) const
{
	std::vector<int>::const_iterator	ita;
	std::vector<int>::const_iterator	itb;
	int	min_distance = min_base_value;
	int	current_distance = 0;

	if (this->_initialized_elements <= 1)
		throw Span::NotEnoughNumbersException();

	for (ita = this->_internal_vector->begin(); ita != this->_internal_vector->end(); ita++) {
		for (itb = (ita + 1); itb != this->_internal_vector->end(); itb++) {
			current_distance = std::abs(*ita - *itb);
			f(&current_distance, &min_distance);
		}
	}
	return (min_distance);
}

void	Span::addNumber(const int value)
{
	if (this->_initialized_elements >= this->_internal_vector->size())
		throw Span::LimitReachException();
	(*this->_internal_vector)[this->_initialized_elements++] = value;
	return ;
}

static void	checkLongest(int *current_distance, int* min_distance) {
	if (*current_distance > *min_distance)
		*min_distance = *current_distance;
}

static void	checkShortest(int *current_distance, int* min_distance) {
	if (*current_distance < *min_distance)
		*min_distance = *current_distance;
}

int	Span::longestSpan(void) const
{
	return (this->_checkSpan(std::numeric_limits<int>::min(), checkLongest));
}

int	Span::shortestSpan(void) const
{
	return (this->_checkSpan(std::numeric_limits<int>::max(), checkShortest));
}

/*
void	Span::printInternalBuffer(void) const
{
	std::vector<int>::const_iterator print_iterator;
	for (print_iterator = this->_internal_vector->begin(); print_iterator != this->_internal_vector->end(); print_iterator++)
		std::cout << *print_iterator << ' ';
	std::cout << std::endl;
}
*/
