#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << name << " : BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed\n";
}
