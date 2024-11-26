#include "MutantStack.hpp"
#include <list>
#include <iostream>

int	main(void)
{
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "stack top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "stack size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		std::cout << "iterate through MutanStack ↓" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "-- end of iteration --" << std::endl;
		std::stack<int> s(mstack);
	}

	std::cout << "\n---- SWITCHING CONTEXT ----\n" << std::endl;

	{
		std::list<int>	mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "stack top: " << *(--mstack.end()) << std::endl;

		mstack.erase(--mstack.end());

		std::cout << "stack size: " << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		std::cout << "iterate through list ↓" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "-- end of iteration --" << std::endl;
		std::list<int> s(mstack);
	}
	return (0);
}
