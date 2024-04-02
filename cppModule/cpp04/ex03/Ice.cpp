#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice& rhs)
{
	type = rhs.type;
}

Ice& Ice::operator=(const Ice& rhs)
{
	if (this == &rhs)
		return *this;

	type = rhs.type;
	return *this;
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
	Ice *ret = new Ice();
	return ret;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}
