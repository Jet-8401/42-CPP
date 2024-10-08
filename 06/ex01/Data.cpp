#include <cstdlib>
#include <ctime>
#include "Data.hpp"

int	Data::seed_flucuator = 0;

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Data::Data(void): hello("Hello World!")
{
    std::srand(std::time(0) + this->seed_flucuator);
    this->random_seed = std::rand();
    this->seed_flucuator += 100;
    return ;
}

Data::Data(const Data& src): random_seed(src.random_seed), hello("Hello World!")
{}

Data::~Data(void)
{}

// Operator overloads
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Data&	Data::operator=(const Data& rhs)
{
	this->random_seed = rhs.random_seed;
	return (*this);
}
