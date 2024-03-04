#include "Zombie.hpp"

void err(){
	system("leaks -q zombie");
}

int main()
{
	atexit(err);
	Zombie *horde1 = zombieHorde(5, "GroupAZombie");
	Zombie *horde2 = zombieHorde(10, "GroupBZombie");

	for (int i = 0; i < 5; i++) {
		horde1[i].announce();
	}

	for (int i = 0; i < 10; i++) {
		horde2[i].announce();
	}

	delete[] horde1;
	delete[] horde2;

	return 0;
}
