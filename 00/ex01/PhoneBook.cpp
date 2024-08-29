#include "PhoneBook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook(void):
	_contacts_set(0),
	_oldest_contact(0)
{}

void	PhoneBook::add(void)
{
	std::cout << "Adding a contact [" << this->_oldest_contact << "]:\n";

	if (!this->_contacts[this->_oldest_contact].create())
		return ;
	if (this->_contacts_set < CONTACTS_N)
		this->_contacts_set++;
	this->_oldest_contact = (this->_oldest_contact + 1) % CONTACTS_N;
}

void	PhoneBook::display_contacts(void)
{
	unsigned int	index;

	index = 0;

	while (index < this->_contacts_set)
	{
		this->_contacts[index].preview(index);
		index++;
	}
}

void	PhoneBook::search(void)
{
	unsigned int	index;

	if (this->_contacts_set == 0)
	{
		std::cout << "No contact already set, you can add by typing 'ADD'\n";
		return ;
	}
	this->display_contacts();
	std::cout << "Enter the index of the contact you want the informations"
		" to be displayed: ";
	std::cin >> index;
	if (!validate_extraction() || index > CONTACTS_N
		|| index > (this->_contacts_set - 1))
		std::cout << "\x1B[31mInvalid index contact !\x1B[0m\n";
	else
		this->_contacts[index].print();
}

void	PhoneBook::exit_cmd(void)
{
	std::cout << "exiting program...\n";
	exit(0);
}
