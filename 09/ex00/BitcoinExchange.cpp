#include "BitcoinExchange.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(const char *db_file_name)
{
	this->loadDB(db_file_name);
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

bool	BitcoinExchange::loadDB(const char *db_file_name)
{
	std::ifstream	db(db_file_name, std::ifstream::in);

	if (db.fail() || db.bad())
		return (this->_error(db_file_name), 0);

}
