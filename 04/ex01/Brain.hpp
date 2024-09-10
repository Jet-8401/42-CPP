#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
	public:
		Brain(void);
		Brain(const Brain& rhs);
		~Brain(void);

		Brain&	operator=(const Brain& rhs);

		std::string	ides[100];
};

#endif
