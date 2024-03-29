#include "ScavTrap.hpp"

int main()
{
	ScavTrap robot1("meka1");
	ScavTrap robot2(robot1);
	ScavTrap robot3;
	robot3 = robot2;

	robot1.attack("enemy1");
	robot1.guardGate();
	robot1.beRepaired(1);
	robot1.takeDamage(1);

	std::cout << std::endl;
	std::cout << "------------using energy all------------------------------------" << std::endl;
	for (int i = 0; i < 50; i++) {
		robot1.attack("enemy1");
	}
	std::cout << "------------------------------------------------------------" << std::endl;
	
	robot1.guardGate();
	robot1.takeDamage(100);
	robot1.takeDamage(1);
	robot1.guardGate();

	std::cout << std::endl << "------------check others attacks------------------------------------" << std::endl; 
	robot2.attack("enemy2");
	robot3.attack("enemy3");
	std::cout << "------------------------------------------------------------" << std::endl;

	// ClapTrap* robot0 = (new ScavTrap("meka2"));
	// robot0->attack("enemy2");
	// robot0->beRepaired(1);
	// robot0->takeDamage(100);

	// delete robot0;
	return (0);
}
