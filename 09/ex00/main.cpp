#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

#define ERR_USAGE "usage: ./btc <database>"
#define ERR_OPEN_FILE "Cannot open file: "

int	main(int argc, char *argv[])
{
	std::ifstream	db;
	std::ifstream	user_db;
	BitCoinExchange	btc;

	if (argc != 2)
		return (std::cerr << ERR_USAGE << std::endl, 0);
	db.open("data.csv", std::ifstream::in);
	if (db.fail() || db.bad())
		return (std::cerr << ERR_OPEN_FILE << "<Intern db file>" << std::endl, 0);
	user_db.open(argv[1], std::ifstream::in);
	if (user_db.fail() || user_db.bad())
		return (std::cerr << ERR_OPEN_FILE << argv[1] << std::endl, 0);
	btc.registerDB(db);
	btc.comparePriceExchange(user_db);
	return (0);
}
