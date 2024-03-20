#include "ClapTrap.hpp"

int main()
{
	ClapTrap marine1("marine");
	ClapTrap marine2(marine1);
	ClapTrap marine3;
	marine3 = marine2;

	std::cout << "--------------------------------marine1--------------------------------" << std::endl;
	//스테미나 소모 초과
	for (int i = 0; i < 12; i++){
		marine1.attack("enemy1");
	}

	std::cout << "--------------------------------marine2--------------------------------" << std::endl;

	marine2.attack("enemy2");
	marine2.takeDamage(1);
	marine2.takeDamage(2);
	marine2.beRepaired(3);
	marine2.beRepaired(5);
	marine2.takeDamage(100);
	marine2.takeDamage(3);
	marine2.beRepaired(100);

	std::cout << "--------------------------------marine3--------------------------------" << std::endl;

	for(int i = 0; i < 5; i++) {
		marine3.attack("enemy3");
	}
	for (int i = 0 ; i < 6; i++) {
		marine3.beRepaired(100);
	}
	
	std::cout << "------------------------------------------------------------------------" << std::endl;
	return 0;
}
