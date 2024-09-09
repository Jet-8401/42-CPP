#pragma once

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& rhs);
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap& rhs);

		void	attack(const std::string& target);
		void	guardGate(void);

	protected:
		bool	_keeper_mode;

	private:
		void	_announce(void);
};

#endif
