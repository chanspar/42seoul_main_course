#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);
	virtual ~Dog();
	virtual void makeSound() const;
	void showDogBrain() const;
};

#endif
