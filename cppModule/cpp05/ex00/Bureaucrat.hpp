#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
private:
	const std::string name;
	unsigned int grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat& rhs);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();
	const std::string getName() const;
	unsigned int getGrade() const;
	void incrementGrade();
	void decrementGrade();

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
