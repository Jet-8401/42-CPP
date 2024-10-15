#include "BitcoinExchange.hpp"
#include <ctime>
#include <cstdlib>
#include <string>
#include <sys/types.h>
#include <time.h>
#include <utility>
#include <iostream>

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

BitCoinExchange::BitCoinExchange(void): _db_pos(this->_internal_db.begin())
{}

BitCoinExchange::~BitCoinExchange(void)
{}

// Function members
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

bool	BitCoinExchange::_parseFile(std::ifstream& stream, void (BitCoinExchange::*f)(time_t key, double value), char c)
{
	std::string	date, value;
	struct tm	timestamp;
	time_t		date_integer;
	double		value_integer;
	uint		line_number = 0;

	while (true)
	{
		line_number++;
		std::getline(stream, date, c);
		std::getline(stream, value);

		if (stream.eof())
			return (true);

		// checking for failure
		strptime(date.c_str(), "%Y-%m-%d", &timestamp);
		date_integer = mktime(&timestamp);
		value_integer = std::atof(value.c_str());
		(this->*f)(date_integer, value_integer);
	}
	return (true);
}

void	BitCoinExchange::_map(time_t key, double value)
{
	this->_internal_db.insert(std::make_pair(key, value));
	std::cout << "key: " << key << "\tvalue: " << value << std::endl;
	return ;
}

void	BitCoinExchange::_compare(time_t key, double value)
{
	std::cout << "key: " << key << "\tvalue: " << value << std::endl;
	return ;
}

bool	BitCoinExchange::registerDB(std::ifstream& stream)
{
	return this->_parseFile(stream, &BitCoinExchange::_map, ',');
}

void	BitCoinExchange::comparePriceExchange(std::ifstream& stream)
{
	std::cout << "appelle compare" << std::endl;
	this->_parseFile(stream, &BitCoinExchange::_compare, '|');
	return ;
}
