#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
		this->templates[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &src) : IMateriaSource(src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src.templates[i])
			this->templates[i] = src.templates[i]->clone();
		else
			this->templates[i] = 0;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete this->templates[i];
			if (rhs.templates[i])
				this->templates[i] = rhs.templates[i]->clone();
			else
				this->templates[i] = 0;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
		delete this->templates[i];
}

// Takes ownership of m: it is stored to be cloned later, and deleted if the
// source is already full (so the caller's `new` never leaks).
void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (this->templates[i] == m)
			return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!this->templates[i])
		{
			this->templates[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->templates[i] && this->templates[i]->getType() == type)
			return (this->templates[i]->clone());
	}
	return (0);
}
