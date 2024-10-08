#include <iomanip>
#include <ios>
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data	someData;

	std::cout << someData.random_seed << std::endl;
	std::cout << someData.hello << std::endl;

	uintptr_t serializedData = Serializer::serialize(&someData);
	Data *originData = Serializer::deserialize(serializedData);

	std::cout << std::setw(35) << std::left << "Original pointer address: "
		<< &someData << std::endl;
	std::cout << "Address passed through serializer: " << originData << std::endl;
	std::cout << (*originData).random_seed << std::endl;
	std::cout << (*originData).hello << std::endl;
	return (0);
}
