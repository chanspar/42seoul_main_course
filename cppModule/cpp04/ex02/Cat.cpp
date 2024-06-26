#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	type = rhs.type;
	brain = new Brain(*rhs.brain);
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this == &rhs)
		return *this;
	delete brain;
	type = rhs.type;
	brain = new Brain(*rhs.brain);
	std::cout << "Cat Copy assignment operator called" << std::endl;

	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat is destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meow!" << std::endl;
}

void Cat::showCatBrain() const
{
	std::cout << "brain address: " << brain << std::endl;
}
