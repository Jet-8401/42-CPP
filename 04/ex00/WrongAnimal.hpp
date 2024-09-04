#pragma once

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& rhs);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(const WrongAnimal& rhs);

		void				makeSound(void) const;
		const std::string&	getType(void) const;

	protected:
		std::string	_type;
};

#endif
