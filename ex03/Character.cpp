#include "Character.hpp"

Character::Character(void) : name("default")
{
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = 0;
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; ++i)
		this->inventory[i] = 0;
}

Character::Character(Character const &src) : ICharacter(src), name(src.name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i]->clone();
		else
			this->inventory[i] = 0;
	}
}

// Subject: the old Materias must be deleted before the new ones are added.
Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; ++i)
		{
			delete this->inventory[i];
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i]->clone();
			else
				this->inventory[i] = 0;
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; ++i)
		delete this->inventory[i];
}

std::string const &Character::getName(void) const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		// equipping the same materia twice would lead to a double delete
		if (this->inventory[i] == m)
			return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
	}
}

// The materia is NOT deleted: the caller must have saved its address.
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !this->inventory[idx])
		return ;
	this->inventory[idx]->use(target);
}

AMateria *Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= 4)
		return (0);
	return (this->inventory[idx]);
}
