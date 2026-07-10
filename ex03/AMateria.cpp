#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) : type("")
{
}

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::AMateria(AMateria const &src) : type(src.type)
{
}

// The type identifies the concrete materia: assigning one materia to another
// must not overwrite it (subject: "copying the type doesn't make sense").
AMateria &AMateria::operator=(AMateria const &rhs)
{
	(void)rhs;
	return (*this);
}

AMateria::~AMateria(void)
{
}

std::string const &AMateria::getType(void) const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
