#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	name = ClapTrap::name;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}
	
DiamondTrap::DiamondTrap(const DiamondTrap& rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs) 
{
	this->name = rhs.name;
	std::cout << "DiamondTrap " << name << " Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this == &rhs)
		return *this;
	
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	std::cout << "DiamondTrap " << name << " Copy assignment operator called" << std::endl;

	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is destroyed" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << this->name << ", ClapTrap name is " << ClapTrap::name << std::endl;
}
