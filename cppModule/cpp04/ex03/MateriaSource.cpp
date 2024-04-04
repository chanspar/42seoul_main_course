#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++) {
		materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
	for (int i = 0; i < 4; i++) {
		materia[i] = NULL;
	}
	for (int i = 0; i < 4; i++) {
		if (rhs.materia[i]) {
			materia[i] = rhs.materia[i]->clone();
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < 4; i++) {
		if (materia[i]) {
			delete materia[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		materia[i] = NULL;
	}
	for (int i = 0; i < 4; i++) {
		if (rhs.materia[i]) {
			materia[i] = rhs.materia[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++) {
		if (materia[i]) {
			delete materia[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		materia[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!materia[i]) {
			materia[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 3; i > -1; i--) {
		if (materia[i] && materia[i]->getType() == type) {
			return materia[i]->clone();
		}
	}
	return NULL;
}
