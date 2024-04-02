#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure& rhs)
{
	type = rhs.type;
}

Cure& Cure::operator=(const Cure& rhs)
{
	if (this == &rhs)
		return *this;

	type = rhs.type;
	return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	Cure *ret = new Cure();
	return ret;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
