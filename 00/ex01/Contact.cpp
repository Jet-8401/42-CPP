#include "Contact.hpp"

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

// Contact context functions

void	Contact::set_secret(void)
{
	std::cout << "What is the contact's darkest secret (" << SECRET_LEN
		<< " chars max):\n";
	std::cin.ignore();
	std::cin.getline(this->darket_secret, SECRET_LEN);
}

char	*Contact::get_secret(void)
{
	return (this->darket_secret);
}

void	Contact::preview(int index)
{
	std::cout << std::right << std::setw(DISPLAY_LEN) << index << " | ";
	print_preview(this->first_name, true);
	print_preview(this->last_name, true);
	print_preview(this->nickname, false);
}

void	Contact::print(void)
{
	std::cout << "First Name: " << this->first_name << '\n';
	std::cout << "Last Name: " << this->last_name << '\n';
	std::cout << "Nickname: " << this->nickname << '\n';
	std::cout << "Phone number: " << this->phone_number << '\n';
	std::cout << "Darkest secret: " << this->get_secret() << '\n';
}
