#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& rhs)
{
	(void)rhs;
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return *this;
}

Intern::~Intern()
{}

AForm* Intern::cloneShrubbery(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::cloneRobotomy(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::clonePresidentailPardon(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*funcPtr[3])(const std::string) = {&Intern::cloneShrubbery, &Intern::cloneRobotomy, &Intern::clonePresidentailPardon};

	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			AForm* form = (this->*funcPtr[i])(target);
			if (form) {
				std::cout << "intern creates " << name << std::endl;
				return form;
			} else {
				std::cout << "Failed to create form" << std::endl;
				return NULL;
			}
		}
	}
	std::cout << "Requested form not found" << std::endl;
	return NULL;
}
