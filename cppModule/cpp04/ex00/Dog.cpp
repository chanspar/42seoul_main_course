#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	type = rhs.type;
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this == &rhs)
		return *this;
	
	type = rhs.type;
	std::cout << "Dog Copy assignment operator called" << std::endl;

	return *this;
}
	
Dog::~Dog()
{
	std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "woof-woof, ruff-ruff, bark!" << std::endl;
}
