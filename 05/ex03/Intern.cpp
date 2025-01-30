#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copy Constructor Called" << std::endl;
	(void)src;
}

Intern	&Intern::operator=(const Intern &src)
{
	std::cout << "Intern Copy Operator Called" << std::endl;
	(void)src;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor Called" << std::endl;
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) const
{
	AForm	*form;

	form = nullptr;
	if (name == "shrubbery creation")
	{
		std::cout << "Intern creates ShurubberyCreationForm." << std::endl;
		form = new ShrubberyCreationForm(target);
	}
	else if (name == "robotomy request")
	{
		std::cout << "Intern creates RobotomyRequestForm." << std::endl;
		form = new RobotomyRequestForm(target);
	}
	else if (name == "presidential pardon")
	{
		std::cout << "Intern creates PersidentialPardonForm." << std::endl;
		form = new PresidentialPardonForm(target);
	}
	else
		std::cout << "Intern doesn't create any Form." << std::endl;
	return form;
}
