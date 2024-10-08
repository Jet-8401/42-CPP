#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data {
	public:
		Data(void);
		Data(const Data& src);
		~Data(void);

		Data&	operator=(const Data& rhs);

		static int	seed_flucuator;
		long		random_seed;
		std::string	hello;
};

#endif
