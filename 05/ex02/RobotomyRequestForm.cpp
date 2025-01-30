#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm Copy Operator Called" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
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
	else
	{
		throw (std::runtime_error(this->getName() + " is not signed."));
	}
}

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
	const AForm *formPtr;

	formPtr = &form;
	out << *formPtr;
	out << ", target " << form.getTarget();
	return out;
}
