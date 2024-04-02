#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"


class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& rhs);
	Cure& operator=(const Cure& rhs);
	virtual ~Cure();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};


#endif
