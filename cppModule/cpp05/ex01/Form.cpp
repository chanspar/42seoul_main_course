#include "Form.hpp"

Form::Form() : name("master"), isSigned(false), signGrade(1), exeGrade(1)
{}

Form::Form(const std::string name, const unsigned int signGrade, const unsigned int exeGrade)
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

Form::Form(const Form& rhs) 
	: name(rhs.name), isSigned(rhs.isSigned), signGrade(rhs.signGrade), exeGrade(rhs.exeGrade)
{}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs) {
		isSigned = rhs.isSigned;
	}
	return *this;
}

Form::~Form()
{}

const std::string Form::getName() const
{
	return name;
}

bool Form::getSigned() const
{
	return isSigned;
}

unsigned int Form::getSignGrade() const
{
	return signGrade;
}

unsigned int Form::getExeGrade() const
{
	return exeGrade;
}

void Form::beSigned(Bureaucrat& rhs)
{
	if (rhs.getGrade() > signGrade) {
		throw GradeTooLowException();
	}
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << "Name: " << form.getName() << std::endl;
	out << "is Signed: " << form.getSigned() << std::endl;
	out << "grade required to sign: " << form.getSignGrade() << std::endl;
	out << "grade required to execute: " << form.getExeGrade() << std::endl;
	return out;
}
