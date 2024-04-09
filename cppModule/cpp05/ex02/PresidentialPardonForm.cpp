#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PardonProject", 25, 5), target("A")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PardonProject", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
	: AForm(rhs.getName(), rhs.getSignGrade(), rhs.getExeGrade()), target(rhs.target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs) {
		target = rhs.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned()) {
		throw SignException();
	}
	if (getExeGrade() < executor.getGrade()) {
		throw GradeTooLowException();
	}
	std::cout << target << " was pardoned by Zaphod Beeblebrox." << std::endl;
}
