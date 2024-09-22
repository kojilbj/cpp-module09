#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm("PresidentialPardonForm", 25, 5), _target(src.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &src)
{
	out << "Form Name: " << src.getName() << ",Grade To Sign: " << src.getGradeSign() << ",Grade To Execute: " << src.getGradeExe() << ",Target: " << src.getTarget();
	return (out);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == true)
	{
		if (this->getGradeExe() < executor.getGrade())
			throw (AForm::GradeTooLowException());
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}