#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(const Cat& rhs);
	Cat& operator=(const Cat& rhs);
	virtual ~Cat();
	virtual void makeSound() const;
};


#endif
