#include "AForm.hpp"

AForm::AForm() : name(""), isSigned(false), signGrade(1), exeGrade(1)
{}

AForm::AForm(const std::string name, const unsigned int signGrade, const unsigned int exeGrade)
	: name(name), isSigned(false), signGrade(signGrade), exeGrade(exeGrade)
{
	if (signGrade < 1) {
		throw GradeTooHighException();
	}
	else if (signGrade > 150) {
		throw GradeTooLowException();
	}
	if (exeGrade < 1) {
		throw GradeTooHighException();
	}
	else if (exeGrade > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm& rhs) 
	: name(rhs.name), isSigned(rhs.isSigned), signGrade(rhs.signGrade), exeGrade(rhs.exeGrade)
{}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs) {
		isSigned = rhs.isSigned;
		const_cast<std::string&>(name) = rhs.name;
		const_cast<unsigned int&>(signGrade) = rhs.signGrade;
		const_cast<unsigned int&>(exeGrade) = rhs.exeGrade;
	}
	return *this;
}

AForm::~AForm()
{}

const std::string AForm::getName() const
{
	return name;
}

bool AForm::getSigned() const
{
	return isSigned;
}

unsigned int AForm::getSignGrade() const
{
	return signGrade;
}

unsigned int AForm::getExeGrade() const
{
	return exeGrade;
}

void AForm::beSigned(Bureaucrat& rhs)
{
	if (rhs.getGrade() > signGrade) {
		throw GradeTooLowException();
	}
	isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char* AForm::SignException::what() const throw()
{
	return "Unsigned";
}

std::ostream& operator<<(std::ostream& out, const AForm& aform)
{
	out << "Name: " << aform.getName() << std::endl;
	out << "is Signed: " << aform.getSigned() << std::endl;
	out << "grade required to sign: " << aform.getSignGrade() << std::endl;
	out << "grade required to execute: " << aform.getExeGrade() << std::endl;
	return out;
}
