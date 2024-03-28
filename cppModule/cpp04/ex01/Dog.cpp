#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	type = rhs.type;
	brain = new Brain();
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this == &rhs)
		return *this;
	delete brain;
	type = rhs.type;
	brain = new Brain(*rhs.brain);
	std::cout << "Dog Copy assignment operator called" << std::endl;

	return *this;
}
	
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "woof-woof, ruff-ruff, bark!" << std::endl;
}
