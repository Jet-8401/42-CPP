#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap John = ClapTrap("John");

	John.attack("a grandma");
	John.attack("a grandma");
	John.attack("a grandma");
	John.takeDamage(5);
	John.beRepaired(5);
	John.attack("a grandma");
	John.attack("a grandma");
	John.attack("a grandma");
	John.attack("a grandma");
	John.takeDamage(9);
	John.attack("a grandma");
	John.attack("a grandma");
	John.attack("a grandma");
	John.attack("a grandma");
	John.beRepaired(20);
	John.takeDamage(4);
	John.attack("a grandma");
	John.takeDamage(100);

	return (0);
}
