#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "nothing";
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
{
	type = rhs.type;
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this == &rhs)
		return *this;
	
	type = rhs.type;
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;

	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal is destroyed" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal class: makeSound()" << std::endl;
}
	
std::string WrongAnimal::getType() const
{
	return type;
}
