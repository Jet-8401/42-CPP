#ifndef WHATEVER_HPP
# define WHATEVER_HPP

namespace {

	template <typename T>
	void swap(T& a, T& b)
	{
		T	copy = a;

		a = b;
		b = copy;
		return ;
	}

	template <typename T>
	T&	min(T& a, T& b)
	{
		return (a > b ? b : a);
	}

	template <typename T>
	T&	max(T& a, T& b)
	{
		return (a < b ? b : a);
	}

}

#endif
