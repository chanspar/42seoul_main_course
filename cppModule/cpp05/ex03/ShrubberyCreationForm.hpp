#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
	virtual ~ShrubberyCreationForm();
	std::string asciiTrees() const;
	void createFile() const;
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
