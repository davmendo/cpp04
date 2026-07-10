#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ARRAY_SIZE 10

int main(void)
{
	std::cout << "===== Animal is now abstract =====" << std::endl;
	{
		// const Animal *meta = new Animal(); // does not compile anymore:
		// "cannot allocate an object of abstract type 'Animal'"
		std::cout << "new Animal() no longer compiles (see commented line)" << std::endl;

		const Animal *j = new Dog();
		const Animal *i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();

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

	std::cout << "\n===== Deep copies still work =====" << std::endl;
	{
		Dog original;

		original.getBrain()->setIdea(0, "chase the ball");
		Dog copy(original);
		original.getBrain()->setIdea(0, "sleep all day");
		std::cout << "original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "copy idea[0]:     " << copy.getBrain()->getIdea(0) << std::endl;

		Cat first;
		Cat second;

		first.getBrain()->setIdea(0, "nap on the keyboard");
		second = first;
		first.getBrain()->setIdea(0, "knock the glass over");
		std::cout << "first idea[0]:  " << first.getBrain()->getIdea(0) << std::endl;
		std::cout << "second idea[0]: " << second.getBrain()->getIdea(0) << std::endl;
	}

	std::cout << "\n===== References to the abstract base =====" << std::endl;
	{
		Dog dog;
		const Animal &ref = dog;

		std::cout << ref.getType() << ": ";
		ref.makeSound();
	}

	std::cout << "\n===== WrongAnimal is still instantiable =====" << std::endl;
	{
		const WrongAnimal *w = new WrongCat();
		const WrongAnimal wrongMeta;

		w->makeSound();
		wrongMeta.makeSound();
		delete w;
	}
	return (0);
}
