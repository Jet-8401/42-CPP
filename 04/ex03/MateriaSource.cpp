#include <cstring>
#include "MateriaSource.hpp"
#include "AMateria.hpp"

// Constructors / Destructors
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

MateriaSource::MateriaSource(void)
{
	memset(&this->materias, 0, sizeof(this->materias));

	return ;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	memset(&this->materias, 0, sizeof(this->materias));
	*this = rhs;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < MATERIAS_N; i++)
	{
		delete this->materias[i];
		this->materias[i] = NULL;
	}
	return ;
}

// Operator overload
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	for (int i = 0; i < MATERIAS_N; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
		if (rhs.materias[i])
			this->materias[i] = rhs.materias[i]->clone();
	}
	return (*this);
}

// Function member
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
		return ;
	for(int i = 0; i < MATERIAS_N; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = materia;
			return ;
		}
	}
	delete materia;
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
