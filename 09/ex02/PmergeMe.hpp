#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>

typedef std::list<unsigned int> p_list;

/*

[19, 27, 83, 3, 85, 54, 89, 68, 1, 52, 55]
     !    !      !      !          !   !
(19,27) (83,3) (85,54) (89,68) (1,52) (55)

for lists copies, extract the number from the origin array for puting it into the new one.

*/

int	pmerge_list(p_list& list);

#endif
