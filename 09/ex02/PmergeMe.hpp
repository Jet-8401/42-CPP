#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>

// Using lists
typedef struct s_int_link {
	std::list<struct s_int_link*>	links;
	unsigned int					value;
}	t_int_link;

typedef std::list<t_int_link> p_list;

int		pmergeList(p_list& list);

// Using vectors
typedef std::vector<unsigned int> p_vector;

p_vector	pmergeVector(p_vector& vector);

#endif
