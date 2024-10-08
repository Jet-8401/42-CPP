#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);

		ScalarConverter&	operator=(const ScalarConverter& rhs);

	public:
		~ScalarConverter(void);

		static void convert(const char *base);
};

#endif
