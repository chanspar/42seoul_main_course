#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	type = str;
}

Weapon::~Weapon()
{
	
}

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string type)
{
	this->type = type;
}
