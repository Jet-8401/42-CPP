#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream> // to delete

Base::~Base(void)
{}

Base*	Base::generate(void)
{
	static unsigned long	seed_flucuator = 0;
	int						choice = 0;

	seed_flucuator += reinterpret_cast<unsigned long>(&choice);
	std::srand(std::time(0) * (seed_flucuator + 1));
    choice = std::rand() % 3;

    std::cout << "choice: " << choice << std::endl;

    switch (choice) {
    case 1:
     return(dynamic_cast<Base *>(new B));
     break;
     case 2:
     return (dynamic_cast<Base *>(new C));
     break;
     default:
     return (dynamic_cast<Base *>(new A));
     break;
    }
}

void	Base::identify(Base* p)
{
	std::cout << "pointer p origin is class ";

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void	Base::identify(Base& p)
{
	std::cout << "reference p origin is class ";

	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else
		std::cout << "C";
}
