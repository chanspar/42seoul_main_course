#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& rhs);
	ScavTrap& operator=(const ScavTrap& rhs);
	virtual ~ScavTrap();
	void guardGate();
	virtual void attack(const std::string& target);
};

#endif
