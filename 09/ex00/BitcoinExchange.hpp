#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <ctime>
# include <map>

class BitcoinExchange {
	private:
		void	_error(const char* message) const;

		std::map<time_t, double>	_internal_container;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const char *db_file_name);
		BitcoinExchange(const BitcoinExchange& src);
		virtual ~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange& rhs);

		bool	loadDB(const char *db_file_name);
};

#endif
