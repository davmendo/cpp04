#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(Animal const &src);
		Animal &operator=(Animal const &rhs);
		virtual ~Animal(void);

		std::string const &getType(void) const;
		virtual void makeSound(void) const;
};

#endif
