#include "Zombie.hpp"

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

//스택은 지역 변수나 임시 변수와 같이 짧은 수명을 가지는 객체에 적합
// 힙은 동적으로 생성된 객체나 긴 수명을 가지는 객체에 적합
// 스택: 스택은 일반적으로 제한된 크기를 가지고 있습니다. 작은 크기의 객체나 함수 호출 시 사용되는 지역 변수 등에 적합합니다.
// 힙: 힙은 스택보다 더 큰 메모리 공간을 제공할 수 있습니다. 큰 크기의 객체나 동적으로 생성된 객체에 적합합니다.
//스택: 스택은 메모리 할당과 해제가 빠르며, 오버헤드가 적습니다.
// 힙: 힙은 메모리 할당과 해제가 상대적으로 느리며, 오버헤드가 큽니다.