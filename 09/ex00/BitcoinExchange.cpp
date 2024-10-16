#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(const char *db_file_name)
{
	std::ifstream	db;

	if (db.fail() || db.bad())
		this->_error(db_file_name);
	this->parseFile(',', db, &BitcoinExchange::insertMap);
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src): _internal_container(src._internal_container)
{}

BitcoinExchange::~BitcoinExchange(void)
{}

// Operator overloads
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	this->_internal_container = rhs._internal_container;
	return (*this);
}

// Function members
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	BitcoinExchange::_error(const char* message) const
{
	std::cerr << "BitcoinEchange Error> ";
	perror(message);
	return ;
}

bool	parseLine(const std::string& line, char c, time_t& date, float& value)
{
	struct tm			raw_time;
	std::string			str;
	std::size_t			break_index;
	std::stringstream	ss;

	break_index = line.find(c);
	str = line.substr(0, break_index);
	memset(&raw_time, 0, sizeof(struct tm));
	if (strptime(str.c_str(), "%Y-%m-%d", &raw_time) == NULL)
		return (false);
	date = mktime(&raw_time);
	if (date == -1)
		return (false);
	str = line.substr(break_index + 1);
	ss << str;
	ss >> value;
	if (!ss.eof() || ss.fail())
		return (false);
	return (true);
}

bool	BitcoinExchange::parseFile(char c, std::ifstream& stream, void (BitcoinExchange::*f)(time_t, float))
{
	std::string			line;
	time_t				date;
	float				value;
	bool				return_val;

	return_val = true;
	while (!stream.eof() && std::getline(stream, line))
	{
		if (parseLine(line, c, date, value)) {
			(this->*f)(date, value);
			continue ;
		}
		return_val = false;
		std::cout << "Error bad input => " << line << std::endl;
	}
	return (return_val);
}

void	BitcoinExchange::insertMap(time_t date, float value)
{
	this->_internal_container.insert(std::pair<time_t, float>(date, value));
	std::cout << "date: " << date << "\tvalue: " << value << std::endl;
}

void	BitcoinExchange::compareDB(time_t date, float value)
{
	float	x;

	if (value < 0 || value > 1000)
	{
		std::cout << "Error bad input: value not between 0 and 1000" << std::endl;
		return ;
	}
	try {
		x = this->_internal_container.at(date);
	} catch (std::exception& e) {
		std::cout << "date not found: " << date << std::endl;
		return ;
	}
	std::cout << "date found: " << date << " => " << x * value << std::endl;
}
