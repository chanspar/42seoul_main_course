#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const unsigned int signGrade;
	const unsigned int exeGrade;
public:
	AForm();
	AForm(const std::string name, const unsigned int signGrade, const unsigned int exeGrade);
	AForm(const AForm& rhs);
	AForm& operator=(const AForm& rhs);
	virtual ~AForm();
	const std::string getName() const;
	bool getSigned() const;
	unsigned int getSignGrade() const;
	unsigned int getExeGrade() const;
	void beSigned(Bureaucrat& rhs);
	virtual void execute(Bureaucrat const & executor) const = 0;

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

	class SignException : public std::exception
	{
		public :
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& aform);

#endif
