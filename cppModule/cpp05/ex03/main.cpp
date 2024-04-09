#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// void a()
// {
// 	system("leaks -q a.out");
// }

int main()
{
	// atexit(a);
	try
	{
		Bureaucrat A("A", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {
			A.signForm(*rrf);
			A.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;

		rrf = someRandomIntern.makeForm("shrubbery creation", "suwon");
		if (rrf) {
			A.signForm(*rrf);
			A.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;

		rrf = someRandomIntern.makeForm("presidential pardon", "tom");
		if (rrf) {
			A.signForm(*rrf);
			A.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;

		rrf = someRandomIntern.makeForm("pasdjfkljsdklfj", "tom");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
