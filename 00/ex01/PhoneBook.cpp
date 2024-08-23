#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->current_contacts = 0;
}

void	PhoneBook::add(void)
{
	std::cout << "Adding a contact (" << this->current_contacts << "):\n";
	std::cout << "First Name:\n";
	std::cin >> this->contacts[this->current_contacts].first_name;
	std::cout << "Last Name:\n";
	std::cin >> this->contacts[this->current_contacts].last_name;
	std::cout << "Nickname:\n";
	std::cin >> this->contacts[this->current_contacts].nickname;
	std::cout << "Phone Number:\n";
	std::cin >> this->contacts[this->current_contacts].phone_number;
	this->contacts[this->current_contacts].set_secret();
	this->current_contacts++;
	if (std::cin.eof())
		std::cout << "\x1B[31mSomething went wrong... :(\x1B[0m\n";
	else
		std::cout << "\x1B[32mSuccessfully added the contact !\x1B[0m\n";
}

void	PhoneBook::display_contacts(void)
{
	int	index;

	index = -1;
	while (++index < this->current_contacts)
		this->contacts[index].preview(index);
}

void	PhoneBook::search(void)
{
	int	index;

	if (this->current_contacts == 0)
	{
		std::cout << "No contact already set, you can add by typing 'ADD'\n";
		return ;
	}
	display_contacts();
	std::cout << "Enter the index of the contact you want the informations"
		" to be displayed: ";
	std::cin >> index;
	if (index > CONTACTS_N || index > (this->current_contacts - 1))
		std::cout << "\x1B[31mInvalid index contact !\x1B[0m\n";
	else
		this->contacts[index].print();
}

void	PhoneBook::exit_cmd(void)
{
	std::cout << "exiting program...\n";
	exit(0);
}
