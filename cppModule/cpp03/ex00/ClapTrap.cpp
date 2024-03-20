#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "guest";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{

	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	std::cout << name << " Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	if (this == &rhs)
		return *this;

	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;
	std::cout << name << " Copy assignment operator called" << std::endl;

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!energyPoints || !hitPoints){
		std::cout << name << " can't attack" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!hitPoints){
		std::cout << name << "'s health already 0" << std::endl;
		return ;
	}
	if (hitPoints < amount){
		hitPoints = 0;
	}
	else{
		hitPoints -= amount;
	}
	std::cout << name << " is damaged " << amount << " ,hitPoints: " << hitPoints << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energyPoints){
		std::cout << name << " doesn't have energy points" << std::endl;
		return ;
	}
	if (!hitPoints){
		std::cout << name << " is already died.." << std::endl;
		return ;
	}
	energyPoints--;
	for (size_t i = 0; i < amount && hitPoints < maxHp; i++){
		hitPoints++;
	}
	std::cout << name << " is repaired " << amount << " ,hitPoints: " << hitPoints << std::endl;
}
