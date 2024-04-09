#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& rhs);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
	virtual ~PresidentialPardonForm();

	virtual void execute(Bureaucrat const & executor) const;
};



#endif
