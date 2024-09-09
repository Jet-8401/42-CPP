#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	John("John");

	John.attack("a guy in the street");
	John.whoAmI();
	John.attack("an other random guy");
	John.takeDamage(10000);
	John.highFivesGuys();
	John.beRepaired(10);
	John.guardGate();

	return (0);
}
