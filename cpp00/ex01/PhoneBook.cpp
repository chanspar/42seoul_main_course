#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	cnt = 1;
	pos = 0;
}

void	PhoneBook::incleaseCnt()
{
	if (cnt <= 8)
		cnt++;
	if (pos <= 7)
		pos++;
}

void PhoneBook::addNewContact()
{
	std::string s;

	if (cnt == 9)
	{
		if (pos == 8)
			pos = 0;
		checkAddContact(s);
		pos++;
	}
	else
	{
		checkAddContact(s);
		incleaseCnt();
	}
}

void PhoneBook::searchContact()
{

}

std::string	PhoneBook::getString()
{
	std::string s;

	while (1)
	{
		getline(std::cin, s);
		if (std::cin.eof()) {
			std::exit(1);
		}
		if(s.find_first_not_of(" \t\n\v\f\r") != std::string::npos)
			return s;
		else
			std::cout << "just input enter or space try again\n";	
	}
}

bool PhoneBook::checkName(const std::string s)
{
	for (size_t i = 0; i < s.length(); i++) {
		if (!std::isalpha(s[i])) {
			std::cout << "input alphabet\n";
			return false;
		}
	}
	return true;
}

bool PhoneBook::checkNickName(const std::string s)
{
	for (size_t i = 0; i < s.length(); i++) {
		if (!std::isalnum(s[i]) && s[i] != '_') {
			std::cout << "check nickname form\n";
			return false;
		}
	}
	return true;
}

bool PhoneBook::checkPhoneNumber(const std::string s)
{
	if (s.length() != 13)
	{
		std::cout << "enter length 13\n";
		return false;
	}

	if (s.substr(3, 1) != "-" || s.substr(8, 1) != "-")
	{
		std::cout << "check hyphen\n";
		return false;
	}

	for (int i = 0; i < 13; i++)
	{
		if (i == 3 || i == 8)
			continue;
		if (!std::isdigit(s[i]))
		{
			std::cout << "enter digit\n";
			return false;
		}
	}
	return true;
}

void	PhoneBook::checkAddContact(std::string s)
{
	bool	isTrue;

	std::cout << "---input firstName (just using alpha)---\n";
	do{
		s = getString();
		isTrue = checkName(s);
	} while(!isTrue);
	contact[pos].setFirstName(s);

	std::cout << "---input lastName (just using alpha)---\n";
	do{
		s = getString();
		isTrue = checkName(s);
	} while(!isTrue);
	contact[pos].setLastName(s);

	std::cout << "---input nickName (just using alpha, number, _)---\n";
	do{
		s = getString();
		isTrue = checkNickName(s);
	} while(!isTrue);
	contact[pos].setNickName(s);

	std::cout << "---input phoneNumber (like 010-0000-0000)---\n";
	do{
		s = getString();
		isTrue = checkPhoneNumber(s);
	} while(!isTrue);
	contact[pos].setPhoneNumber(s);

	std::cout << "---input darkestSecret---\n";
	s = getString();
	contact[pos].setDarkestSecret(s);
}
