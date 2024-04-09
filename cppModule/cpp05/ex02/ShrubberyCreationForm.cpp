#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShruberryProject", 145, 137), target("home")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShruberryProject", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
	: AForm(rhs.getName(), rhs.getSignGrade(), rhs.getExeGrade()), target(rhs.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs) {
		target = rhs.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

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
}
