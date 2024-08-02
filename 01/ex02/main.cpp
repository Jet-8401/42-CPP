#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*pointer = &str;
	std::string &ref = str;

	std::cout << &str << '\n';
	std::cout << pointer << '\n';
	std::cout << &ref << '\n';

	std::cout << str << '\n';
	std::cout << *pointer << '\n';
	std::cout << ref << '\n';
	return (0);
}
