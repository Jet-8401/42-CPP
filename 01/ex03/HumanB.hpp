#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {

	public:
		HumanB	(std::string);
		void	attack(void);
		void	setWeapon(Weapon&);

	private:
		Weapon		*weapon;
		std::string name;
};

#endif
