#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
	std::string asciiTrees() const;
	void createFile() const;
	virtual void execute(Bureaucrat const & executor) const;
};

#endif
