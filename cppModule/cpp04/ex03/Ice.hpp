#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"


class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& rhs);
	Ice& operator=(const Ice& rhs);
	virtual ~Ice();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
