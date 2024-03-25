#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs)
{
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	std::cout << "ScavTrap " << name << " Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this == &rhs)
		return *this;

	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	std::cout << "ScavTrap " << name << " Copy assignment operator called" << std::endl;

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
	if (!hitPoints){
		std::cout << "ScavTrap " << name << " can't doing" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!energyPoints || !hitPoints){
		std::cout << "ScavTrap " << name << " can't attack" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
}
