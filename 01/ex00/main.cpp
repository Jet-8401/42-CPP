#include "Zombie.hpp"

int	main(void)
{
	Zombie	*bob = new Zombie("Bob");
	Zombie	*NotBob = bob->newZombie("Baby from bob");

	bob->announce();
	bob->randomChump("I am a random guy");
	NotBob->announce();
	delete bob;
	delete NotBob;

	return (0);
}
