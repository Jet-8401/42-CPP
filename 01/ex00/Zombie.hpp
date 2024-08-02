#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie {
	public:
		Zombie		(std::string name);
		~Zombie 	(void);
		void		announce(void);
		void		randomChump(std::string name);
		Zombie*		newZombie(std::string name);
	private:
		std::string name;
};

#endif
