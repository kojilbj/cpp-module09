#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Constructor Called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern	&Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor Called" << std::endl;
}

AForm	*Intern::makeForm(const std::string &nameForm, const std::string &target) const
{
	AForm	*form;
	int	type;

	type = checkFormType(nameForm);
	form = nullptr;
	if (type == 0)
		form = new ShrubberyCreationForm(target);
	else if (type == 1)
		form = new RobotomyRequestForm(target);
	else if (type == 2)
		form = new PresidentialPardonForm(target);
	return (form);
}

int	Intern::checkFormType(const std::string &nameForm) const
{
	if (nameForm == "shrubbery creation")
		return (0);
	else if (nameForm == "robotomy request")
		return (1);
	else if (nameForm == "presidential pardon")
		return (2);
	return (-1);
}