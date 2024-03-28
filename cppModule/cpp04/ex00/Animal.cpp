#include "Animal.hpp"

Animal::Animal()
{
	type = "nothing";
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal& rhs)
{
	type = rhs.type;
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	if (this == &rhs)
		return *this;
	
	type = rhs.type;
	std::cout << "Animal Copy assignment operator called" << std::endl;

	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal is destroyed" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal class: makeSound()" << std::endl;
}
	
std::string Animal::getType() const
{
	return type;
}
