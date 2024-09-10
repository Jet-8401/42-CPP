#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << meta->getType() << std::endl;

		cat->makeSound(); //will output the cat sound!
		dog->makeSound();
		meta->makeSound();

		delete meta;
		delete dog;
		delete cat;
	}
	{
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* dog = new Dog();
		const WrongAnimal* cat = new WrongCat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << meta->getType() << std::endl;

		cat->makeSound(); //will output the wrong animal sound!
		dog->makeSound();
		meta->makeSound();

		((WrongCat*) cat)->makeSound(); //will output the wrong cat sound!

		delete meta;
		delete dog;
		delete cat;
	}

	return (0);
}
