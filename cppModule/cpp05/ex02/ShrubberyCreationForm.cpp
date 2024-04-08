#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target(""), AForm("Shruberry", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: target(target), AForm("Shruberry", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
	: target(rhs.target), AForm(rhs.getName(), rhs.getSignGrade(), rhs.getExeGrade())
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs) {
		const_cast<std::string&>(target) = rhs.target;
	}
	return *this;
}

std::string ShrubberyCreationForm::asciiTrees() const
{
	return  "    ^        ^    \n"
        "   /|\\      /|\\   \n"
        "  / | \\    / | \\  \n"
        " /  |  \\  /  |  \\ \n"
        "/___|___\\/___|___\\\n"
        "   |||       |||    \n";
}

void ShrubberyCreationForm::createFile() const
{
	std::string filename = target + "_shrubbery";

	std::ofstream file(filename.c_str());
	if (file.is_open()) {
		file << asciiTrees();
	}
	else {
		std::cerr << "Failed to open file.." << std::endl; 
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned()) {
		throw SignException();
	}
	if (getExeGrade() < executor.getGrade()) {
		throw GradeTooLowException();
	}
	createFile();
	return ;
}
