#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	cnt = 0;
	pos = 0;
}

void	PhoneBook::incleaseCnt()
{
	if (cnt < 8)
		cnt++;
	if (pos < 8)
		pos++;
}

void PhoneBook::addNewContact()
{
	std::string s;

	if (pos == 8)
		pos = 0;
	checkAddContact(s);
	incleaseCnt();
}

std::string	PhoneBook::getString()
{
	std::string s;

	while (1)
	{
		getline(std::cin, s);
		if (std::cin.eof()) {
			clearerr(stdin);
			std::cin.clear();
			std::cout << "you try eof, input correct form plz\n";
		}
		else if (std::cin.fail()) {
			std::cout << "cin fail, input corret index plz\n";
			clearerr(stdin);
			std::cin.clear();
		}
		else if(s.find_first_not_of(" \t\n\v\f\r") != std::string::npos)
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

void PhoneBook::searchContact()
{
	bool isTrue = false;

	if (cnt != 0) {
		std::cout << "|" << std::setw(10) << "index" << "|";
		std::cout << std::setw(10) << "firstName" << "|";
		std::cout << std::setw(10) << "lastName" << "|";
		std::cout << std::setw(10) << "nickName" << "|\n";}
	for (int i = 0; i < cnt; i++) {
		std::cout << "|" <<std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << checkLength(contact[i].getFirstName()) << "|";
		std::cout << std::setw(10) << checkLength(contact[i].getLastName()) << "|";
		std::cout << std::setw(10) << checkLength(contact[i].getNickName()) << "|\n";
	}
	if (cnt == 0) {
		std::cout << "No list contact\n";
	}
	else {
		std::cout << "select index number\n";
		std::string	str;
		while (!isTrue) {
			getline(std::cin, str);
			int	idx = std::atoi(str.c_str());
			if (0 < idx && idx <= cnt && str.length() == 1) {
				displayContact(idx);
				isTrue = true;
			}
			else if (std::cin.eof()) {
				std::cout << "you input ctrl+d\n";
				clearerr(stdin);
				std::cin.clear();
			}
			else if (std::cin.fail()) {
				std::cout << "cin fail, input corret index plz\n";
				clearerr(stdin);
				std::cin.clear();
			}
			else {
				std::cout << "wrong index number try again\n";
			}
		}
	}
}

std::string PhoneBook::checkLength(std::string s)
{
	if (s.length() > 10) {
		return s.substr(0, 9) + "."; 
	}
	return s;
}

void	PhoneBook::displayContact(int idx)
{
	std::cout << "------------------------contact information------------------------\n";
	std::cout << "fisrtName: " << contact[idx - 1].getFirstName() << "\n";
	std::cout << "lastName: " << contact[idx - 1].getLastName() << "\n";
	std::cout << "nickName: " << contact[idx - 1].getNickName() << "\n";
	std::cout << "phoneNumber: " << contact[idx - 1].getPhoneNumber() << "\n";
	std::cout << "darkestSecret: " << contact[idx - 1].getDarkestSecret() << "\n";
	std::cout << "-------------------------------------------------------------------\n";
}
