#include "Contact.hpp"
#include "main.hpp"

std::string trunc_property(std::string value)
{
	if (value.length() > DISPLAY_LEN)
		return (value.substr(0, DISPLAY_LEN - 1) + '.');
	return (value);
}

void	print_preview(std::string value, bool separation)
{
	std::cout << std::right << std::setw(DISPLAY_LEN) << trunc_property(value);
	std::cout << (separation ? " | " : "\n");
}

// Construstor

Contact::Contact(void): _is_already_set(0) {}

// Contact context functions

bool	Contact::create(void)
{
	char	choice;
	if (this->_is_already_set)
	{
		std::cout << "The contact list is full, if you add the contact it"\
			"will overwrite the oldest contact !\nAre you sure ? [y / n]:\n";
		std::cin >> choice;
		if (!validate_extraction() || choice != 'y')
		{
			std::cout << "Returning to menu..." << std::endl;
			return (0);
		}
	}

	this->_is_already_set = 1;

	std::cout << "First Name:\n";
	std::cin >> this->_first_name;
	std::cout << "Last Name:\n";
	std::cin >> this->_last_name;
	std::cout << "Nickname:\n";
	std::cin >> this->_nickname;
	std::cout << "Phone Number:\n";
	std::cin >> this->_phone_number;

	this->set_secret();

	if (std::cin.eof())
		std::cout << "\x1B[31mSomething went wrong... :(\x1B[0m\n";
	else
		std::cout << "\x1B[32mSuccessfully added the contact !\x1B[0m\n";
	return (1);
}

void	Contact::set_secret(void)
{
	std::cout << "What is the contact's darkest secret: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, this->_darkest_secret, '\n');
}

std::string&	Contact::get_secret(void)
{
	return (this->_darkest_secret);
}

void	Contact::preview(int index)
{
	std::cout << std::right << std::setw(DISPLAY_LEN) << index << " | ";
	print_preview(this->_first_name, true);
	print_preview(this->_last_name, true);
	print_preview(this->_nickname, false);
}

void	Contact::print(void)
{
	std::cout << "First Name: " << this->_first_name << '\n';
	std::cout << "Last Name: " << this->_last_name << '\n';
	std::cout << "Nickname: " << this->_nickname << '\n';
	std::cout << "Phone number: " << this->_phone_number << '\n';
	std::cout << "Darkest secret: " << this->get_secret() << '\n';
}

void	Contact::clear(void)
{
	this->_first_name.clear();
	this->_last_name.clear();
	this->_nickname.clear();
	this->_phone_number.clear();
	this->_darkest_secret.clear();
}
