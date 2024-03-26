#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

//깊은 복사는 실제로 두개의 값이 생성되는 것
//얕은 복사는 값은 여전히 하나인데 접근 포인터가 2개인것

// void a()
// {
// 	system("leaks a.out");
// }

int main()
{
	// atexit(a);
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete i;
		delete j;
		delete meta;
	}
	{
		std::cout << "------------------------check wrongClass-------------------" << std::endl;
		const WrongAnimal* wAnimal = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		std::cout << std::endl << "----------------------------checkType-------------------------" << std::endl;
		std::cout << "wrongAnimal type: " << wAnimal->getType() << " " << std::endl;
		std::cout << "wrongCat type: " << wrongCat->getType() << " " << std::endl << std::endl;;
		std::cout << "----------------------------checkSound-------------------------" << std::endl;
		std::cout << "execute wrongAnimal makeSound(): " << std::endl;
		wAnimal->makeSound();
		std::cout << "execute wrongCat makeSound(): " << std::endl;
		wrongCat->makeSound();
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		delete wrongCat;
		delete wAnimal;
	}
	return 0;
}