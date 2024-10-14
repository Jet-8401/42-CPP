#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <exception>
# include <vector>

typedef unsigned int uint;

class Span {
	private:
		Span(void);

		int	_checkSpan(int min_base_value, void (*f)(int*, int*)) const;

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
		void	addNumber(Iterator begin, Iterator end);
		void	addNumber(const int value);
		int	shortestSpan(void) const;
		int	longestSpan(void) const;

		//void	printInternalBuffer(void) const; // for debug
};

template <typename InputIterator>
void	Span::addNumber(InputIterator first, InputIterator last)
{
	long distance = std::distance(first, last);
	if (distance < 0)
		return ;
	if (static_cast<unsigned long>(distance) > this->_internal_vector->size() - this->_initialized_elements)
		throw Span::LimitReachException();
	std::copy(first, last, this->_internal_vector->begin() + this->_initialized_elements);
	this->_initialized_elements += distance;
	return ;
}

#endif
