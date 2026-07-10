#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ARRAY_SIZE 10

int main(void)
{
	std::cout << "=========== Subject test ===========" << std::endl;
	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();

		delete j;
		delete i;
	}

	std::cout << "\n===== Array of Animals (half Dog, half Cat) =====" << std::endl;
	{
		const Animal *animals[ARRAY_SIZE];

		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			if (i < ARRAY_SIZE / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			std::cout << animals[i]->getType() << ": ";
			animals[i]->makeSound();
		}
		std::cout << "--- deleting everyone as Animal* ---" << std::endl;
		for (int i = 0; i < ARRAY_SIZE; ++i)
			delete animals[i];
	}

	std::cout << "\n===== Deep copy: copy constructor =====" << std::endl;
	{
		Dog original;

		original.getBrain()->setIdea(0, "chase the ball");
		Dog copy(original);
		original.getBrain()->setIdea(0, "sleep all day");
		std::cout << "original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "copy idea[0]:     " << copy.getBrain()->getIdea(0) << std::endl;
		if (original.getBrain() != copy.getBrain())
			std::cout << "OK: brains are two distinct objects (deep copy)" << std::endl;
		else
			std::cout << "KO: brains share the same address (shallow copy!)" << std::endl;
	}

	std::cout << "\n===== Deep copy: assignment operator =====" << std::endl;
	{
		Cat first;
		Cat second;

		first.getBrain()->setIdea(0, "nap on the keyboard");
		second = first;
		first.getBrain()->setIdea(0, "knock the glass over");
		std::cout << "first idea[0]:  " << first.getBrain()->getIdea(0) << std::endl;
		std::cout << "second idea[0]: " << second.getBrain()->getIdea(0) << std::endl;
		if (first.getBrain() != second.getBrain())
			std::cout << "OK: brains are two distinct objects (deep copy)" << std::endl;
		else
			std::cout << "KO: brains share the same address (shallow copy!)" << std::endl;
	}

	std::cout << "\n===== Copy of a Cat as a stack object =====" << std::endl;
	{
		Cat cat;

		cat.getBrain()->setIdea(42, "world domination");
		Cat clone(cat);
		std::cout << "clone idea[42]: " << clone.getBrain()->getIdea(42) << std::endl;
	}

	std::cout << "\n===== Wrong family still behaves wrong =====" << std::endl;
	{
		const WrongAnimal *w = new WrongCat();

		w->makeSound();
		delete w;
	}
	return (0);
}
