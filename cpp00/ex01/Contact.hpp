#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
public:
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
	void		setFirstName(std::string param);
	void		setLastName(std::string param);
	void		setNickName(std::string param);
	void		setPhoneNumber(std::string param);
	void		setDarkestSecret(std::string param);
};

#endif
