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

AForm	*Intern::makeShrubberyCreationForm(const std::string &target) const
{
	std::cout << "Intern creates ShurubberyCreationForm." << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeRobotomyRequestForm(const std::string &target) const
{
	std::cout << "Intern creates RobotomyRequestForm." << std::endl;
	return new RobotomyRequestForm(target);
}

AForm	*Intern::makePresidentialPardonForm(const std::string &target) const
{
	std::cout << "Intern creates PersidentialPardonForm." << std::endl;
	return new PresidentialPardonForm(target);
}
AForm	*Intern::makeForm(const std::string &name, const std::string &target) const
{
	AForm	*form;
	std::string	forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
		};
	AForm*	(Intern::*createFuncs[])(const std::string &target) const = {
		&Intern::makeShrubberyCreationForm, 
		&Intern::makeRobotomyRequestForm, 
		&Intern::makePresidentialPardonForm
		};

	form = nullptr;
	for (size_t i = 0; i < sizeof(forms) - 1; i++)
	{
		if (name == forms[i])
		{
			form = (this->*createFuncs[i])(target);
			break ;
		}
	}
	if (form == nullptr)
		std::cout << "Intern doesn't create any Form." << std::endl;
	return form;
}
