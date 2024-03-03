#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>
# include <cstdio>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
	int		cnt;
	int		pos;
public:
	PhoneBook();
	void	addNewContact();
	void	incleaseCnt();
	void	searchContact();
	std::string	getString();
	bool 	checkName(const std::string s);
	bool 	checkNickName(const std::string s);
	bool 	checkPhoneNumber(const std::string s);
	void	checkAddContact(std::string s);
	std::string	checkLength(std::string s);
	void	displayContact(int idx);
};

#endif