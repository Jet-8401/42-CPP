#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <ctime>
#include <fstream>
# include <map>

class BitcoinExchange {
	private:
		void	_error(const char* message) const;

		std::map<time_t, float>	_internal_container;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const char *db_file_name);
		BitcoinExchange(const BitcoinExchange& src);
		virtual ~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange& rhs);

		void	insertMap(time_t date, float value);
		void	compareDB(time_t date, float value);
		bool	parseFile(char c, std::ifstream& stream, void (BitcoinExchange::*f)(time_t, float));
};

#endif
