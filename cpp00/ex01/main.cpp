#include "PhoneBook.hpp"

int	main()
{
	std::string	command;
	PhoneBook	phoneBook;

	while(1)
	{
		std::cout << "---input ADD or SEARCH or EXIT---\n";
		getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addNewContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT" || std::cin.eof()) {
			break ;
		}
		else if (std::cin.fail()) {
			return (1);
		}
		else
			std::cout << "input correct command!!" << std::endl;
	}
	return (0);
}
