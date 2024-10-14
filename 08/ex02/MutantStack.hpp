#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>

namespace {

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T> {
	public:
		MutantStack<T, Container>(void): std::stack<T, Container>()
		{}
		// create a constructor that can instentiate through the provided
		// underlying container as std::list::list does

		MutantStack<T, Container>(const MutantStack<T, Container>& src): std::stack<T, Container>()
		{
			*this = src;
			return ;
		}

		virtual ~MutantStack<T, Container>(void)
		{}

		MutantStack<T, Container>&	operator=(const MutantStack<T, Container>& rhs)
		{
			if (this == &rhs)
				return (*this);
			std::stack<T, Container>::operator=(rhs);
			return (*this);
		}

		typedef typename std::stack<T, Container>::iterator iterator;
};

}

#endif
