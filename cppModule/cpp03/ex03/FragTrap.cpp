#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hitPoints = 100;
	// energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	hitPoints = 100;
	// energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs)
{
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	std::cout << "FragTrap " << name << " Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	if (this == &rhs)
		return *this;

	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	std::cout << "FragTrap " << name << " Copy assignment operator called" << std::endl;

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (!hitPoints){
		std::cout << "FragTrap " << name << " can't doing" << std::endl;
		return ;
	}
	std::cout << "FragTrap Give me some high fives, guys!" << std::endl;
}
