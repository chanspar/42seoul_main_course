#include "FragTrap.hpp"

int main()
{
	FragTrap robot1("meka1");
	FragTrap robot2(robot1);
	FragTrap robot3;
	robot3 = robot2;

	robot1.attack("enemy1");
	robot1.highFivesGuys();
	robot1.beRepaired(1);
	robot1.takeDamage(1);

	std::cout << std::endl;
	std::cout << "------------using energy all------------------------------------" << std::endl;
	for (int i = 0; i < 100; i++) {
		robot1.attack("enemy1");
	}
	std::cout << "------------------------------------------------------------" << std::endl;
	
	robot1.takeDamage(100);
	robot1.takeDamage(1);
	robot1.highFivesGuys();


	std::cout << std::endl << "------------check others attacks------------------------------------" << std::endl; 
	robot2.attack("enemy2");
	robot3.attack("enemy3");
	std::cout << "------------------------------------------------------------" << std::endl;

	return (0);
}
