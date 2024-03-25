#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& rhs);
	FragTrap& operator=(const FragTrap& rhs);
	virtual ~FragTrap();
	void highFivesGuys(void);
};

#endif
