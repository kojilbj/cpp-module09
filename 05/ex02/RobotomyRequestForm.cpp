#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &src)
{
	out << "Form Name: " << src.getName() << ",Grade To Sign: " << src.getGradeSign() << ",Grade To Execute: " << src.getGradeExe() << ",Target: " << src.getTarget();
	return (out);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	int	random;

	if (this->getIsSigned() == true)
	{
		if (this->getGradeExe() < executor.getGrade())
			throw (AForm::GradeTooLowException());
		std::srand(std::time(0));
		random = std::rand();
		if (random % 2 == 0)
			std::cout << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << _target << " has not been robotomized" << std::endl;
	}
}