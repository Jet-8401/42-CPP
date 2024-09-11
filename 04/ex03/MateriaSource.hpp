#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define MATERIAS_N 4

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& rhs);
		~MateriaSource(void);

		MateriaSource&	operator=(const MateriaSource& rhs);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(const std::string& type);

		AMateria*	materias[MATERIAS_N];
};

#endif
