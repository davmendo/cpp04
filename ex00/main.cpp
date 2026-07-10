#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "=========== Subject test ===========" << std::endl;
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n===== Wrong family (non-virtual) =====" << std::endl;
	{
		const WrongAnimal *wrongMeta = new WrongAnimal();
		const WrongAnimal *w = new WrongCat();

		std::cout << w->getType() << " " << std::endl;
		w->makeSound();
		wrongMeta->makeSound();

		delete wrongMeta;
		delete w;
	}

	std::cout << "\n===== Stack objects and references =====" << std::endl;
	{
		Dog dog;
		Cat cat;
		const Animal &animalRef = dog;
		const Animal &otherRef = cat;

		animalRef.makeSound();
		otherRef.makeSound();

		WrongCat wrongCat;
		const WrongAnimal &wrongRef = wrongCat;

		wrongRef.makeSound();
		wrongCat.makeSound();
	}

	std::cout << "\n===== Copy constructor and assignment =====" << std::endl;
	{
		Dog basic;
		Dog copy(basic);
		std::cout << "copy type: " << copy.getType() << std::endl;
		copy.makeSound();

		Cat cat;
		Cat assigned;
		assigned = cat;
		std::cout << "assigned type: " << assigned.getType() << std::endl;
		assigned.makeSound();
	}

	std::cout << "\n===== Array of Animal pointers =====" << std::endl;
	{
		const Animal *animals[4];

		animals[0] = new Dog();
		animals[1] = new Cat();
		animals[2] = new Dog();
		animals[3] = new Cat();
		for (int idx = 0; idx < 4; ++idx)
		{
			std::cout << animals[idx]->getType() << ": ";
			animals[idx]->makeSound();
		}
		for (int idx = 0; idx < 4; ++idx)
			delete animals[idx];
	}
	return (0);
}
