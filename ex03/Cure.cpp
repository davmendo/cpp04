#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(Cure const &src) : AMateria(src)
{
}

Cure &Cure::operator=(Cure const &rhs)
{
	AMateria::operator=(rhs);
	return (*this);
}

Cure::~Cure(void)
{
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
