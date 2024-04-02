#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materia[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& rhs);
	MateriaSource& operator=(const MateriaSource& rhs);
	virtual ~MateriaSource();


	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);

};

#endif
