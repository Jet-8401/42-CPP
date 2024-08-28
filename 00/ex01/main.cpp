#include "PhoneBook.hpp"

int	main(void)
{
	const char	*keys[KEYS] = {"ADD", "SEARCH", "EXIT"};
	void	(PhoneBook::*function[])(void) =
		{&PhoneBook::add, &PhoneBook::search, &PhoneBook::exit_cmd};
	int			i;
	std::string	entry;
	PhoneBook	phonebook;

	std::cout << "Welcome to your phonebook !\nThe command available are: "
		<< keys[0] << ',' << keys[1] << ',' << keys[2] << ":\n";

	while (!std::cin.eof()) {
		std::cout << "\x1B[34mphonebook> \x1B[0m";
		std::cin >> entry;
		i = 0;
		while (i < KEYS && keys[i] != entry)
			i++;
		if (i < KEYS)
			(phonebook.*function[i])();
		else
			std::cout << "\x1B[1;31mUnrecognized command !\x1B[0m\n";
	}
	return (0);
}
