#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *templates[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		MateriaSource &operator=(MateriaSource const &rhs);
		virtual ~MateriaSource(void);

		virtual void learnMateria(AMateria *m);
		virtual AMateria *createMateria(std::string const &type);
};

#endif
