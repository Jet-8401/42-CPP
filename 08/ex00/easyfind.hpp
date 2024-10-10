#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>

namespace {
	template<typename T>
	typename T::iterator	easyfind(T& container, int to_search)
	{
		for (typename T::iterator it = container.begin(); it != container.end(); it++)
			if (*it == to_search)
				return (it);
		return (container.end());
	}
};

#endif
