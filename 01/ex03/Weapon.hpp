#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {

	public:
		Weapon				(std::string);
		std::string const	&getType(void) const;
		void				setType(std::string type);

	private:
		std::string	type;
};

#endif
