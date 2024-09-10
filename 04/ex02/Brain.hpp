#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# define IDEAS_N 100

class Brain {
	public:
		Brain(void);
		Brain(const Brain& rhs);
		~Brain(void);

		Brain&	operator=(const Brain& rhs);

		std::string	ideas[IDEAS_N];
};

#endif
