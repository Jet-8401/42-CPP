#pragma once

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap& rhs);
		DiamondTrap(const std::string& name);
		~DiamondTrap(void);

		DiamondTrap&	operator=(const DiamondTrap& rhs);

		void	whoAmI(void);

	private:
		void	_announce(void);

		std::string	_name;
};


#endif
