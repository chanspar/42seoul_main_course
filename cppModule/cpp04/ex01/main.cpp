#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

//깊은 복사는 실제로 두개의 값이 생성되는 것
//얕은 복사는 값은 여전히 하나인데 접근 포인터가 2개인것

// void a()
// {
// 	system("leaks a.out");
// }

int main()
{
	// atexit(a);
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;

	std::cout << "---------------------------------------test-------------------------------------------" << std::endl << std::endl;
	Animal *animalArr[6];

	std::cout << "----------------------------------Dog constructor-------------------------------------" << std::endl;
	for (int i = 0; i < 3; i++) {
		Dog *dog = new Dog();
		animalArr[i] = dog;
	}
	std::cout << std::endl;

	std::cout << "----------------------------------Cat constructor-------------------------------------" << std::endl;
	for (int i = 3; i < 6; i++) {
		Cat *cat = new Cat();
		animalArr[i] = cat;
	}
	std::cout << std::endl;

	std::cout << "----------------------------------animal destructor-------------------------------------" << std::endl;
	for (int i = 0; i < 6; i++) {
		delete animalArr[i];
	}
	std::cout << "---------------------------------------test end-----------------------------------------" << std::endl << std::endl;




	std::cout << "---------------------------------------cat deep copy-----------------------------------------" << std::endl << std::endl;
	Cat	cat1;
	std::cout << "---------------------------------------check copy constructor-----------------------------------------" << std::endl;
	Cat	cat2(cat1);
	std::cout << "---------------------------------------check copy operator-----------------------------------------" << std::endl;
	Cat cat3;
	cat3 = cat1;

	cat1.showCatBrain();
	cat2.showCatBrain();
	cat3.showCatBrain();

	std::cout << std::endl;
	std::cout << "---------------------------------------dog deep copy-----------------------------------------" << std::endl << std::endl;


	Dog dog1;
	std::cout << "---------------------------------------check copy constructor-----------------------------------------" << std::endl;
	Dog dog2(dog1);
	std::cout << "---------------------------------------check copy operator-----------------------------------------" << std::endl;
	Dog dog3;
	dog3 = dog1;

	dog1.showDogBrain();
	dog2.showDogBrain();
	dog3.showDogBrain();

	std::cout << "---------------------------------------fin deep copy-----------------------------------------" << std::endl << std::endl;

	return 0;
}
