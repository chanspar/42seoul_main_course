#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++) {
        this->ideas[i] = "";
    }
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain& rhs)
{
	for (int i = 0; i < 100; i++) {
        this->ideas[i] = rhs.ideas[i];
    }
    std::cout << "Brain Copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this == &rhs)
		return *this;
	
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = rhs.ideas[i];
	}
	std::cout << "Brain Copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain is destroyed" << std::endl;
}
