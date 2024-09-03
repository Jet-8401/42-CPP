#pragma once

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& rhs);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap& rhs);

		void	attack(const std::string& target);
		void	guardGate(void);

	private:
		ScavTrap(void);

		void	_announce(void);

		bool	_keeper_mode;
};

#endif
