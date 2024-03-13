#include "Zombie.hpp"
#include <cstdlib>

void err()
{
	system("leaks -q zombie");
}

int main()
{
	atexit(err);
	Zombie *heapZombie = newZombie("heapzombie");
	Zombie stackZombie1("stackzombie1");

	stackZombie1.announce();
	randomChump("stackzombie2");
	heapZombie->announce();
	delete heapZombie;
	return (0);
}
