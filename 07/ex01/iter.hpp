#ifndef ITER_HPP
# define ITER_HPP

namespace {

	template<typename T>
	void increment(T& a)
	{
		a += 1;
		return ;
	}

	template<typename A, typename L, typename R>
	void	iter(A*	array, L length, R (*f)(A&))
	{
		for (L i = 0; i < length; i++)
			f(array[i]);
		return ;
	}

}

#endif
