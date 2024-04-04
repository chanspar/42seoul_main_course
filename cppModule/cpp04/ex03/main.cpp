#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

// void a()
// {
// 	system("leaks a.out");
// }

int main()
{
	// atexit(a);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	return 0;
}

// int main()
// {
// 	atexit(a);
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");
	
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	//재료 복사 버그
// 	me->equip(tmp); 
// 	me->equip(tmp);

// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
	
// 	//잘못된 재료
// 	tmp = src->createMateria("cure!");
// 	me->equip(tmp);
// 	tmp = src->createMateria("asdf!");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure!");
// 	me->equip(tmp);

// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);

// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);

// 	//재료 5번 초과 
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");
	
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	me->use(2, *bob);
// 	me->use(3, *bob);
// 	me->use(4, *bob);

// 	tmp = me->savePtr(0);	
// 	me->unequip(0);
// 	delete tmp;
// 	tmp = me->savePtr(2);	
// 	me->unequip(2);
// 	delete tmp;
// 	std::cout << "----------------------unequip let's go----------------------" << std::endl;
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	me->use(2, *bob);
// 	me->use(3, *bob);


// 	delete bob;
// 	delete me;
// 	delete src;
	
// 	return 0;
// }

// int main()
// {
// 	atexit(a);
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	Character me;
	
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me.equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me.equip(tmp);
	
// 	ICharacter* bob = new Character("bob");
	
	
// 	me.use(0, *bob);
// 	me.use(1, *bob);
	

// 	Character me1(me);
// 	me1.use(0, *bob);
// 	me1.use(1, *bob);

// 	Character me2;
// 	me2 = me;
// 	me2.use(0, *bob);
// 	me2.use(1, *bob);
// 	tmp = src->createMateria("cure");
// 	me.equip(tmp);
// 	me.use(2, *bob);

// 	me2.use(2, *bob);


// 	delete bob;
// 	delete src;
	
// 	return 0;
// }
