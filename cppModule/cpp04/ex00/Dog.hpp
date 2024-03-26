#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);
	virtual ~Dog();
	virtual void makeSound() const;
};

#endif
