#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs)
{
	type = rhs.type;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this == &rhs)
		return *this;
	
	type = rhs.type;
	std::cout << "Cat Copy assignment operator called" << std::endl;

	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat is destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meow!" << std::endl;
}
