#include "ScavTrap.hpp"

int main()
{
	ScavTrap robot1("meka1");
	ScavTrap robot2(robot1);
	ScavTrap robot3 = robot2;

	// robot1.attack("enemy1");
	// robot1.guardGate();
	// robot1.beRepaired(1);
	// robot1.takeDamage(1);
	// for (int i = 0; i < 50; i++) {
	// 	robot1.attack("enemy1");
	// }
	// robot1.guardGate();
	// robot1.takeDamage(100);
	// robot1.takeDamage(1);
	// robot1.guardGate();

	robot2.attack("enemy2");
	robot3.attack("enemy3");

	// ClapTrap* robot2 = (new ScavTrap("meka2"));
	// robot2->attack("enemy2");
	// robot2->beRepaired(1);
	// robot2->takeDamage(100);

	// delete robot2;
	return (0);
}
