#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const unsigned int signGrade;
	const unsigned int exeGrade;
public:
	Form();
	Form(const std::string name, const unsigned int signGrade, const unsigned int exeGrade);
	Form(const Form& rhs);
	Form& operator=(const Form& rhs);
	~Form();
	const std::string getName() const;
	bool getSigned() const;
	unsigned int getSignGrade() const;
	unsigned int getExeGrade() const;
	void beSigned(Bureaucrat& rhs);

	class GradeTooHighException : public std::exception
	{
		public :
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public :
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
