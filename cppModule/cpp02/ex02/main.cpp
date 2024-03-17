#include "Fixed.hpp"

int main( void ) {
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}

// int main(void) {
// 	Fixed num1(11);
// 	Fixed num2(3);
// 	Fixed num3(3);

// 	std::cout << "---------------comparison operators-------------------" << std::endl;
// 	std::cout << "(num1 > num2): " << (num1 > num2) << std::endl;
// 	std::cout << "(num1 >= num2): " << (num1 >= num2) << std::endl;
// 	std::cout << "(num1 < num2): " <<(num1 < num2) << std::endl;
// 	std::cout << "(num1 <= num2): " << (num1 <= num2) << std::endl;

// 	std::cout << "(num3 >= num2): " << (num3 >= num2) << std::endl;
// 	std::cout << "(num3 <= num2): " << (num3 <= num2) << std::endl;
// 	std::cout << "(num3 == num2): " << (num3 == num2) << std::endl;
// 	std::cout << "(num1 == num2): " << (num1 == num2) << std::endl;

// 	std::cout << "(num3 != num2): " << (num3 != num2) << std::endl;
// 	std::cout << "(num1 != num2): " << (num1 != num2) << std::endl << std::endl;

// 	std::cout << "---------------arithmetic operators-------------------" << std::endl;
// 	Fixed n1(5);
// 	Fixed n2(2);
// 	std::cout << "n1 + n2: " << n1 + n2 << std::endl;
// 	std::cout << "n1 - n2: " << n1 - n2 << std::endl;
// 	std::cout << "n1 * n2: " << n1 * n2 << std::endl;
// 	std::cout << "n1 / n2: " << n1 / n2 << std::endl << std::endl;

// 	std::cout << "--------------- increment/decrement-------------------" << std::endl;
// 	Fixed a;
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << --a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a-- << std::endl;
// 	std::cout << a << std::endl;


// }
