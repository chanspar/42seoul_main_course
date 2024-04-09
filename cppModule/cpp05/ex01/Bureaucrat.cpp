#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("newbie"), grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : name(name)
{
	if (grade > 150) {
		throw GradeTooLowException();
	}
	else if (grade < 1) {
		throw GradeTooHighException();
	}
	else {
		this->grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : name(rhs.name), grade(rhs.grade)
{	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs) {
		grade = rhs.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
	return name;
}
unsigned int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade == 1) {
		throw GradeTooHighException();
	}
	else {
		grade--;
	}
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150) {
		throw GradeTooLowException();
	}
	else {
		grade++;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() <<std::endl;
	return out;
}

void Bureaucrat::signForm(Form& rhs)
{
	if (rhs.getSigned()) {
		std::cout << name << " couldn't sign " << rhs.getName() << " because already signed" << std::endl;
	}
	else {
		try {
			rhs.beSigned(*this);
			std::cout << name << " signed " << rhs.getName() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
