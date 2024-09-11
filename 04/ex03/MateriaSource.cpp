#include "MateriaSource.hpp"
#include "AMateria.hpp"

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

MateriaSource::MateriaSource(void)
{
	return ;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	*this = rhs;
}

MateriaSource::~MateriaSource(void)
{
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	MateriaSource::learnMateria(AMateria *materia)
{
	AMateria	*empty;

	for(int i = 0; i < MATERIAS_N; i++)
	{
		if (!this->materias[i])
		{
			empty = this->materias[i];
			break ;
		}
	}
	empty = materia;
	return ;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for(int i = 0; i < MATERIAS_N; i++)
	{
		if (this->materias[i] && !this->materias[i]->getType().compare(type))
			return (this->materias[i]->clone());
	}
	return (NULL);
}
