#include "iter.hpp"
#include <cstdio>
#include <iostream>
#include <string>

bool	print(std::string& s)
{
	std::cout << s;
	return (true);
}

int	main(void)
{
	{
		int		length = 10;
		char	alphabet[length + 1];

		for (int i = 0; i < length; i++)
			alphabet[i] = 'a' + i;
		alphabet[length] = 0;


		std::cout << std::string(alphabet) << std::endl;
		::iter<char, int, void>(alphabet, length, ::increment<char>);
		std::cout << std::string(alphabet) << std::endl;
		::iter<char, int, void>(alphabet, length, ::increment<char>);
		std::cout << std::string(alphabet) << std::endl;
		::iter<char, int, void>(alphabet, length, ::increment<char>);
		std::cout << std::string(alphabet) << std::endl;
		::iter<char, int, void>(alphabet, length, ::increment<char>);
		std::cout << std::string(alphabet) << std::endl;
		::iter<char, int, void>(alphabet, length, ::increment<char>);
		std::cout << std::string(alphabet) << std::endl;
	}

	{
		std::string	splitted_sentence[7] = {
			"This", " is", " supposed", " to", " be", " a", " sentence"
		};

		::iter<std::string, short, bool>(splitted_sentence, 7, print);
		std::cout << std::endl;
	}
	return (0);
}
