#include <cctype>
#include <cmath>
#include <cstring>
#include <ios>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include "ScalarConverter.hpp"

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void) src;
	return;
}

ScalarConverter::~ScalarConverter(void)
{}

// Operator overloads
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void) rhs;
	return (*this);
}

// Function members
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

bool	extractNumber(const char *string, double *number)
{
	std::string			buffer;
	std::stringstream	container(string);

	container >> *number;
	if (container.fail() || !container.eof())
	{
		container >> buffer;
		if (buffer != "f" || !container.eof())
		{
			std::cout << "char: impossible\nint: impossible\n"
				<< "float: impossible\ndouble: impossible" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	checkPseudoLiteral(const char *string, double *value)
{
	static const std::string pseudo_literals[6] = {"nan", "nanf", "-inf",
		"-inff", "inf", "inff"};
	static const double limits[3] = {
		std::numeric_limits<double>::quiet_NaN(),
		-std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity()
	};

	for (int i = 0; i < 6; i++)
	{
		if (pseudo_literals[i] != string)
			continue ;
		*value = limits[i / 2];
		return (true);
	}
	return (false);
}

void	ScalarConverter::convert(const char *base)
{
	double	value;

	if (std::strlen(base) <= 1 && std::isalpha(base[0]))
		value = static_cast<double>(base[0]);
	else if (!checkPseudoLiteral(base, &value)) {
		if (!extractNumber(base, &value))
			return ;
	}

	std::cout << std::fixed;
	// static_cast<char>
	std::cout << "char: ";
	if (value > std::numeric_limits<char>::max()
		|| value - static_cast<int>(value) != 0)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(value))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << '\'' << static_cast<char>(value) << '\'' << std::endl;
	// static_cast<int>
	std::cout << "int: ";
	if (std::isnan(value) || value > std::numeric_limits<int>::max()
		|| value < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
	// static_cast<float>
	std::cout << "float: ";
	if (!std::isinf(value) && (value > std::numeric_limits<float>::max()
		|| value < std::numeric_limits<float>::min()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(value) << 'f' << std::endl;
	// default value as double
	std::cout << "double: " << value << std::endl;
	return ;
}
