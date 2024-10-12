#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <exception>
# include <vector>

typedef unsigned int uint;

class Span {
	private:
		Span(void);

		uint	_checkSpan(void (*f)(int*, int*)) const;

		std::vector<int>*			_internal_vector;
		uint						_initialized_elements;

	public:
		class NotEnoughNumbersException : public std::exception {
			virtual const char* what() const throw();
		};

		class LimitReachException : public std::exception {
			virtual const char* what() const throw();
		};

		Span(const Span& src);
		Span(const uint N);
		virtual ~Span(void);

		Span&	operator=(const Span& rhs);

		template <typename Iterator>
		void	addNUmber(Iterator begin, Iterator end);
		void	addNumber(const int value);
		uint	shortestSpan(void) const;
		uint	longestSpan(void) const;
};

template <typename Iterator>
void	Span::addNUmber(Iterator first, Iterator last)
{
	// Todo
	return ;
}

#endif
