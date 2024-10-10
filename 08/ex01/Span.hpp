#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
typedef unsigned int uint;

class Span {
	private:
		Span(void);

		uint	_checkSpan(void (*f)(long*, long*)) const;

		uint*	_intern;
		uint	_length;
		uint	_current_index;

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

		void	addNumber(uint n);
		uint	shortestSpan(void) const;
		uint	longestSpan(void) const;
};



#endif
