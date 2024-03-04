#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "string memory address:    " << &str << "\n";
	std::cout << "stringPTR memory address: " << stringPTR << "\n";
	std::cout << "stringREF memory address: " << &stringREF << "\n";
	std::cout << std::endl;
	std::cout << "string value:    " << str << "\n";
	std::cout << "stringPTR value: " << *stringPTR << "\n";
	std::cout << "stringREF value: " << stringREF << "\n";

	return 0;
}
