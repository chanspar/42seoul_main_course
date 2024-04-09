#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& rhs);
	Intern& operator=(const Intern& rhs);
	~Intern();
	AForm* makeForm(const std::string name, const std::string target);

	AForm* cloneShrubbery(const std::string target);
	AForm* cloneRobotomy(const std::string target);
	AForm* clonePresidentailPardon(const std::string target);
};

#endif
