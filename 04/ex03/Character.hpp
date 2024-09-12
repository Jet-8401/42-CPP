#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

# define INVENTORY_SLOTS 4

class Character : public ICharacter {
	protected:
		Character(void);

		AMateria**	_findEmptySlot(void);

		std::string	_name;
		AMateria*	_inv[INVENTORY_SLOTS];

	public:
		Character(const Character& rhs);
		Character(const std::string& name);
		~Character(void);

		Character&	operator=(const Character& rhs);

		AMateria*			getInvSlot(int idx);
		const std::string&	getName(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
