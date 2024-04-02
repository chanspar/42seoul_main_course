#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	AMateria* inventory[4];
	std::string name;
	int			slot[4];
public:
	Character();
	Character(std::string const & name);
	Character(const Character& rhs);
	Character& operator=(const Character& rhs);
	virtual ~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

	AMateria* savePtr(int idx);
};

#endif
