#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);


int main(void)
{
	Point	a(1, 1);
	Point	b(3, 10);
	Point	c(5, 1);

	Point	p1(1, 1);
	Point	p2(5, 5);
	Point	p3(2, 5.5);
	Point	p4(3, 5);

	//점에 있을때
	if (bsp(a, b, c, p1))
		std::cout << "p1 is in the triangle" << std::endl;
	else
		std::cout << "p1 is out of the triangle" << std::endl;
	//삼각형 밖에 있을떄
	if (bsp(a, b, c, p2))
		std::cout << "p2 is in the triangle" << std::endl;
	else
		std::cout << "p2 is out of the triangle" << std::endl;
	//모서리에있을떄
	if (bsp(a, b, c, p3))
		std::cout << "p3 is in the triangle" << std::endl;
	else
		std::cout << "p3 is out of the triangle" << std::endl;
	//삼각형 안에있을때
	if (bsp(a, b, c, p4))
		std::cout << "p4 is in the triangle" << std::endl;
	else
		std::cout << "p4 is out of the triangle" << std::endl;
	return 0;
}