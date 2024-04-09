#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyProject", 72, 45), target("factory")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyProject", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
	: AForm(rhs.getName(), rhs.getSignGrade(), rhs.getExeGrade()), target(rhs.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs) {
		target = rhs.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::robotomizedTry() const
{
	std::cout << "drill whirr whirr whirr~~" << std::endl;
	//랜덤 시드 초기화
	std::srand(static_cast<unsigned int>(std::time(0)));

	//0~99 랜덤 숫자 생성
	int randomValue = std::rand() % 100;

	if (randomValue < 50) {
        std::cout << target << " robotomized success!!" << std::endl;
    } else {
        std::cout << "robotomy failed" << std::endl;
    }
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned()) {
		throw SignException();
	}
	if (getExeGrade() < executor.getGrade()) {
		throw GradeTooLowException();
	}
	robotomizedTry();
}
