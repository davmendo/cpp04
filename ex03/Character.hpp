#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];

	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		Character &operator=(Character const &rhs);
		virtual ~Character(void);

		virtual std::string const &getName(void) const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);

		AMateria *getMateria(int idx) const;
};

#endif
