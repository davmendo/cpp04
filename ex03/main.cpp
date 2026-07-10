#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");

		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n===== Unequip leaves the materia on the floor =====" << std::endl;
	{
		Character alice("alice");
		Character bob("bob");
		AMateria *saved = new Ice();

		alice.equip(saved);
		alice.use(0, bob);
		alice.unequip(0);
		alice.use(0, bob);
		std::cout << "(nothing printed after unequip: slot 0 is empty)" << std::endl;
		delete saved;
	}

	std::cout << "\n===== Full inventory and invalid indexes =====" << std::endl;
	{
		Character full("full");
		Character target("target");

		full.equip(new Ice());
		full.equip(new Cure());
		full.equip(new Ice());
		full.equip(new Cure());

		AMateria *extra = new Ice();
		full.equip(extra);
		if (full.getMateria(0) != extra && full.getMateria(1) != extra
			&& full.getMateria(2) != extra && full.getMateria(3) != extra)
			std::cout << "5th equip ignored (inventory full)" << std::endl;

		full.use(0, target);
		full.use(1, target);
		full.use(2, target);
		full.use(3, target);
		full.use(4, target);
		full.use(-1, target);
		std::cout << "(use with idx 4 and -1 printed nothing)" << std::endl;
		delete extra;
	}

	std::cout << "\n===== Deep copy of a Character =====" << std::endl;
	{
		Character original("original");
		Character dummy("dummy");

		original.equip(new Ice());
		original.equip(new Cure());

		Character copy(original);
		Character assigned("assigned");
		assigned.equip(new Cure());
		assigned = original;

		if (original.getMateria(0) != copy.getMateria(0)
			&& original.getMateria(0) != assigned.getMateria(0))
			std::cout << "OK: copies own their own cloned materias" << std::endl;
		else
			std::cout << "KO: copies share materias (shallow copy!)" << std::endl;
		std::cout << "copy name: " << copy.getName()
			<< " | assigned name: " << assigned.getName() << std::endl;
		copy.use(0, dummy);
		copy.use(1, dummy);
		assigned.use(0, dummy);
		assigned.use(1, dummy);
	}

	std::cout << "\n===== MateriaSource: unknown type and full source =====" << std::endl;
	{
		MateriaSource src;

		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());

		AMateria *unknown = src.createMateria("fire");
		if (unknown == 0)
			std::cout << "createMateria(\"fire\") returned 0 (unknown type)" << std::endl;

		AMateria *known = src.createMateria("cure");
		std::cout << "createMateria(\"cure\") type: " << known->getType() << std::endl;
		delete known;
	}

	std::cout << "\n===== Assigning a materia does not copy its type =====" << std::endl;
	{
		Ice first;
		Ice second;

		second = first;
		std::cout << "second type after assignment: " << second.getType() << std::endl;
	}
	return (0);
}
