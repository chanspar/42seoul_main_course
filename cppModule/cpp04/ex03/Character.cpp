#include "Character.hpp"

Character::Character()
{
	name = "unknown";
	for(int i = 0; i < 4 ; i++) {
		inventory[i] = NULL;
		slot[i] = 0;
	}
}

Character::Character(std::string const & name)
{
	this->name = name;
	for(int i = 0; i < 4 ; i++) {
		inventory[i] = NULL;
		slot[i] = 0;
	}
}

Character::Character(const Character& rhs)
{
	name = rhs.name;
	for (int i = 0; i < 4; i++) {
		if (inventory[i]) {
			delete inventory[i];
		}
	}
	for(int i = 0; i < 4 ; i++) {
		inventory[i] = NULL;
		slot[i] = 0;
	}
	for (int i = 0; i < 4; i++) {
		if (rhs.inventory[i]) {
			inventory[i] = rhs.inventory[i]->clone();
			slot[i] = rhs.slot[i];
		}
	}
}
	
Character& Character::operator=(const Character& rhs)
{
	if (this == &rhs)
		return *this;
	
	name = rhs.name;
	for (int i = 0; i < 4; i++) {
		if (inventory[i]) {
			delete inventory[i];
		}
	}
	for(int i = 0; i < 4 ; i++) {
		inventory[i] = NULL;
		slot[i] = 0;
	}
	for (int i = 0; i < 4; i++) {
		if (rhs.inventory[i]) {
			inventory[i] = rhs.inventory[i]->clone();
			slot[i] = rhs.slot[i];
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++) {
		if (inventory[i]) {
			delete inventory[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
		slot[i] = 0;
	}
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	int idx;

	for (idx = 0; idx < 4; idx++) {
		if (slot[idx] == 0)
			break;
	}
	if (idx == 4 || !m) {
		return ;
	}
	inventory[idx] = m;
	slot[idx] = 1;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !inventory[idx]) {
		return ;
	}
	inventory[idx] = NULL;
	slot[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !inventory[idx]) {
		return ;
	}
	inventory[idx]->use(target);
}

AMateria* Character::savePtr(int idx)
{
	return inventory[idx];
}

