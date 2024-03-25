#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dia1("robot1");
	DiamondTrap dia2(dia1);
	DiamondTrap dia3;
	dia3 = dia2;

	dia1.attack("enemy1");
	dia1.beRepaired(1);
	dia1.takeDamage(1);
	for (int i = 0; i < 50; i++) {
		dia1.attack("enemy1");
	}
	dia1.highFivesGuys();
	dia1.guardGate();
	dia1.whoAmI();

	return (0);
}
