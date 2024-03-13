#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << name << " : BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
