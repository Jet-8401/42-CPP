#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	while (--argc && argv++)
	{
		i = 0;
		while ((*argv)[i])
			std::cout << (char) std::toupper((*argv)[i++]);
	}
	std::cout << std::endl;
	return (0);
}
