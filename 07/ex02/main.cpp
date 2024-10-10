#include <iostream>
#include "Array.hpp"

int	main(void)
{
	::Array<int>	arr(5);
	for (uint i = 0; i < arr.size(); i++) {
		arr[i] = i;
		std::cout << arr[i] << std::endl;
	}

	::Array<int>	arrayCopy(arr);
	::Array<int>	arrayCopyCopy = arrayCopy;
	arrayCopyCopy[0] = 398203;

	std::cout << "-- arrayCopy --" << std::endl;
	::printArray<int>(arrayCopy);
	std::cout << "-- arayCopyCopy --" << std::endl;
	::printArray<int>(arrayCopyCopy);

	std::cout << "-- string array --" << std::endl;
	::Array<char>	string(20);
	for (uint i = 0; i < string.size(); i++)
		string[i] = 'a' + i;

	::Array<char>	smallString(10);
	smallString = string;
	string[1] = 'k';
	::printArray<char>(smallString);
	std::cout << std::endl;

	// smallString[20]; // will throw an exception

	return (0);
}
