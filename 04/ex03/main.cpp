#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	MateriaSource	newSource(*((MateriaSource *) src));

	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	AMateria*	ice = new Ice();
	src->learnMateria(ice);

	ICharacter* me = new Character("me");

	AMateria *tmp1, *tmp2, *tmp3;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	tmp3 = src->createMateria("ice");
	me->equip(tmp3);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	ICharacter*	john = new Character(*((Character *) me));

	john->use(1, *bob);
	john->use(0, *me);

	for (int i = 0; i < 100; i++)
		me->unequip(i);

	me->use(0, *bob);
	bob->use(0, *john);

	Ice	materiaIce(void);
	Ice	materiaIce2(Ice);

	delete tmp1;
	delete tmp2;
	delete tmp3;
	delete bob;
	delete me;
	delete src;
	delete john;
}
