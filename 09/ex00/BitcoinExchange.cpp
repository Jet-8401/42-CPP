#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

BitcoinExchange::BitcoinExchange(void)
{}

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

void	BitcoinExchange::_badInput(const char* reason, const char* line) const
{
	std::cerr << "Error bad input: " << reason << " => " << line << std::endl;
	return ;
}

bool	parseLine(const std::string& line, char& c, time_t& date, float& value)
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

bool	BitcoinExchange::parseFile(char c, std::ifstream& stream,
	bool (BitcoinExchange::*f)(std::string&, time_t&, float&))
{
	std::string			line;
	time_t				date;
	float				value;
	bool				return_val;

	return_val = true;
	std::getline(stream, line); // skip the first line
	while (!stream.eof() && std::getline(stream, line))
	{
		if (parseLine(line, c, date, value)) {
			(this->*f)(line, date, value);
			continue ;
		}
		return_val = false;
		std::cout << "Error bad input => " << line << std::endl;
	}
	return (return_val);
}

bool	BitcoinExchange::insertMap(std::string& line, time_t& date, float& value)
{
	try {
		this->_internal_container.at(date);
	} catch (const std::out_of_range& oor) {
		this->_internal_container.insert(std::pair<time_t, float>(date, value));
		return (1);
	}
	this->_badInput("duplicated value", line.c_str());
	return (0);
}

bool	BitcoinExchange::compareDB(std::string& line, time_t& date, float& value)
{
	float		rate;
	struct tm	*time;
	char		str_time[100];

	if (value < 0)
		return (this->_badInput("not positive number", line.c_str()), 0);
	if (value > 1000)
		return (this->_badInput("number too high", line.c_str()), 0);
	rate = this->rateAt(date);
	time = localtime(&date);
	strftime(str_time, 100, "%Y-%m-%d", time);
	std::cout << str_time << " => " << value << " = " << value * rate << std::endl;
	return (1);
}

// take the closest rate in the data-base from the given time
float	BitcoinExchange::rateAt(time_t& time) const
{
	float						value;
	_cont_type::const_iterator	it;

	try {
		value = this->_internal_container.at(time);
	} catch (const std::out_of_range& oor) {
		it = this->_internal_container.begin();
		while (it != this->_internal_container.end() && it->first < time)
			it++;
		if (it != this->_internal_container.begin())
			it--;
		value = it->second;
	}
	return (value);
}
