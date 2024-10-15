#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <ctime>
# include <fstream>
# include <map>

class BitCoinExchange {
	private:
		typedef std::map<time_t, double> _db_type;

		BitCoinExchange(const BitCoinExchange& src);
		BitCoinExchange&	operator=(const BitCoinExchange& rhs);

		bool	_parseFile(std::ifstream& stream, void (BitCoinExchange::*f)(time_t t, double v), char c);
		void	_map(time_t t, double v);
		void	_compare(time_t t, double v);

		_db_type			_internal_db;
		_db_type::iterator	_db_pos;

	public:
		BitCoinExchange(void);
		virtual ~BitCoinExchange(void);

		bool	registerDB(std::ifstream& stream);
		void	comparePriceExchange(std::ifstream& stream);
};

#endif
