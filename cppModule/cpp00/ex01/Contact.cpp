#include "Contact.hpp"

std::string Contact::getFirstName()
{
	return firstName;
}

std::string Contact::getLastName()
{
	return lastName;
}

std::string Contact::getNickName()
{
	return nickName;
}

std::string Contact::getPhoneNumber()
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return darkestSecret;
}

void	Contact::setFirstName(std::string param)
{
	firstName = param;
}

void	Contact::setLastName(std::string param)
{
	lastName = param;
}

void	Contact::setNickName(std::string param)
{
	nickName = param;
}

void	Contact::setPhoneNumber(std::string param)
{
	phoneNumber = param;
}

void	Contact::setDarkestSecret(std::string param)
{
	darkestSecret = param;
}
