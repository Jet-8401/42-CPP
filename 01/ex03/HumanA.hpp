#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA {

	public:
		HumanA	(std::string, Weapon&);
		void	attack(void);

	private:
		Weapon		&weapon;
		std::string name;
};

#endif
