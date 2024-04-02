#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& rhs);
	Animal& operator=(const Animal& rhs);
	virtual ~Animal();
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif
