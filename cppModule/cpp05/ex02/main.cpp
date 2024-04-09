#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat Bureaucrat1("justin", 1);
		Bureaucrat Bureaucrat2("bob", 145);

		ShrubberyCreationForm shrubbery("house");
		RobotomyRequestForm robotomy("Trasher");
		PresidentialPardonForm pardon("Karen");

		std::cout << "-----------------------sign-----------------------" << std::endl;
		Bureaucrat2.signForm(shrubbery);
		Bureaucrat2.signForm(robotomy);
		Bureaucrat1.signForm(robotomy);
		Bureaucrat1.signForm(pardon);
		Bureaucrat1.signForm(pardon);
		std::cout << std::endl << std::endl; 


		std::cout << "-------------------------exe-------------------------" << std::endl;
		Bureaucrat1.executeForm(shrubbery);
		std::cout << std::endl;
		Bureaucrat1.executeForm(robotomy);
		std::cout << std::endl;
		Bureaucrat1.executeForm(pardon);
		std::cout << std::endl << std::endl;		

		std::cout << "-------------------------fail-------------------------" << std::endl;
		Bureaucrat2.executeForm(shrubbery);
		Bureaucrat2.executeForm(robotomy);
		Bureaucrat2.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
