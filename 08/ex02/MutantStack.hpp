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

		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator begin() { return this->c.begin(); }
    	iterator end() { return this->c.end(); }
    	const_iterator begin() const { return this->c.begin(); }
    	const_iterator end() const { return this->c.end(); }
};

}

#endif
