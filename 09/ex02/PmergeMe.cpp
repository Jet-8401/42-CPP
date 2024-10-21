#include "PmergeMe.hpp"
#include <iostream>
#include <utility>

// Template function to print elements of any container
template <typename Container>
void printContainer(const Container& container, const char* delimiter = " ") {
    typename Container::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it;
        if (it != --container.end()) {
            std::cout << delimiter;
        }
    }
    std::cout << std::endl;
}

// Ford-Johnson Merge-insertion sort using lists.
int	pmerge_list(p_list& list)
{
	p_list::iterator	list_it = list.begin();
	p_list::iterator	end_list = list.end();

	if (list.size() == 2) {
		end_list--;
		if (*list_it > *end_list)
			std::swap(*list_it, *end_list);
		return (0);
	}
	if (list.size() < 2)
		return (0);

	p_list::iterator	next_it = list_it;
	p_list				small_n;
	next_it++;

	if (list.size() % 2 != 0)
		end_list--;

	while (list_it != end_list) {
		p_list::iterator	temp_it = next_it;

		if (temp_it != end_list)
			temp_it++;
		if (*list_it > *next_it) {
			small_n.splice(small_n.end(), list, next_it);
		} else {
			small_n.splice(small_n.end(), list, list_it);
		}

		list_it = temp_it;
		next_it = ++temp_it;
	}

	std::cout << "-- -- -- unsorted -- -- --" << std::endl;
	printContainer(small_n);
	printContainer(list);
	pmerge_list(list);
	std::cout << "-- -- -- split -- -- --" << std::endl;
	printContainer(small_n);
	printContainer(list);

	// now normally the list is into the good order, so we just need to do binary insertion from small_n into list.

	return (0);
}
