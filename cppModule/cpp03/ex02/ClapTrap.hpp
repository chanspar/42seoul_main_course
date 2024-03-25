#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
protected:
	std::string					name;
	unsigned int				hitPoints;
	unsigned int				energyPoints;
	unsigned int				attackDamage;
	static const unsigned int	maxHp = 100000; 

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& rhs);
	ClapTrap& operator=(const ClapTrap& rhs);
	virtual ~ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
