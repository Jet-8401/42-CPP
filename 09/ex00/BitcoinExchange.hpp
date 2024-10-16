#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <ctime>
#include <fstream>
# include <map>

class BitcoinExchange {
	private:
		typedef std::map<time_t, float> _cont_type;

		void	_badInput(const char* reason, const char* line) const;

		_cont_type	_internal_container;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& src);
		virtual ~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange& rhs);

		bool	parseFile(char c, std::ifstream& stream, bool (BitcoinExchange::*f)(std::string&, time_t&, float&));
		bool	insertMap(std::string& line, time_t& date, float& value);
		bool	compareDB(std::string& line, time_t& date, float& value);
		float	rateAt(time_t& time) const;
};

#endif
