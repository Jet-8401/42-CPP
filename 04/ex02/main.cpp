#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	unsigned int	array_size = 50;
	A_Animal*		animals[array_size];

	for(unsigned int i = 0; i < array_size; i++)
	{
		if (i < array_size / 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for(unsigned int i = 0; i < array_size; i++)
		delete animals[i];
}
