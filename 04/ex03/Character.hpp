#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter {
	protected:
		Character(void);

		std::string	_name;
		// implement vectors
		AMateria*	inventory[4];

	public:
		Character(const Character& rhs);
		Character(const std::string& name);
		~Character(void);

		Character&	operator=(const Character& rhs);

		const std::string&	getName() const = 0;
		void				equip(AMateria* m) = 0;
		void				unequip(int idx) = 0;
		void				use(int idx, ICharacter& target) = 0;
};

#endif
