#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat Bureaucrat1("justin", 1);
	Bureaucrat Bureaucrat2("bob", 150);

	ShrubberyCreationForm shrubbery("house");
	RobotomyRequestForm robotomy("Trasher");
	PresidentialPardonForm pardon("Karen");

	std::cout << "-----------------------sign-----------------------" << std::endl;
	Bureaucrat1.signForm(shrubbery);
	Bureaucrat1.signForm(robotomy);
	Bureaucrat1.signForm(pardon);
	std::cout << "-----------------------sign fin-----------------------" << std::endl << std::endl; 


	std::cout << "-----------------------exe-----------------------" << std::endl;
	Bureaucrat1.executeForm(shrubbery);
	Bureaucrat1.executeForm(robotomy);
	Bureaucrat1.executeForm(pardon);

	return 0;
}
