#include "AMateria.hpp"

AMateria::AMateria()
{
	type = "";
}

AMateria::AMateria(std::string const & type)
{
	this->type = type; 
}
	
AMateria::AMateria(const AMateria& rhs)
{
	type = rhs.type;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	if (this == &rhs)
		return *this;
	
	type = rhs.type;
	return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << std::endl;
}
