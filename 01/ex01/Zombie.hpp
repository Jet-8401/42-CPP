#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie {
	public:
		~Zombie 	(void);
		void		set_name(std::string name);
		void		announce(void);
	private:
		std::string name;
};

Zombie	*zombieHorde(int n, std::string name);

#endif
