#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs)
{
	type = rhs.type;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	if (this == &rhs)
		return *this;
	
	type = rhs.type;
	std::cout << "WrongCat Copy assignment operator called" << std::endl;

	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "weird meow!" << std::endl;
}
