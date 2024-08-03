#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n" <<
		"I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n" <<
		"I cannot believe adding extra bacon costs more money. "
		"You didn’t put enough bacon in my burger! If you did, I wouldn’t "
		"be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n" <<
		"I think I deserve to have some extra bacon for free. "
		"I’ve been coming for years whereas you started working here since"
		" last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n"
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	keys[4] = {"INFO", "DEBUG", "WARNING", "ERROR"};
	int i = -1;

	while (++i < 4)
		if (level.compare(keys[i]) == 0)
			break ;
	switch (i) {
		case 0:
			this->info();
			// fall through
		case 1:
			this->debug();
			// fall through
		case 2:
			this->warning();
			// fall through
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	}
}

// f***ing fallthrough of c++98...
