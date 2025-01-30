#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "Intern Default Constructor TEST========" << std::endl;
	{
		Intern	intern;
	}
	std::cout << std::endl;
	std::cout << "Intern Copy Constructor TEST========" << std::endl;
	{
		Intern	intern1;
		Intern	intern2(intern1);
	}
	std::cout << std::endl;
	std::cout << "Intern Copy Operator TEST========" << std::endl;
	{
		Intern	intern1;
		Intern	intern2;

		intern1 = intern2;
	}
	std::cout << std::endl;
	std::cout << "Intern makeForm ShurubberryCreationForm TEST========" << std::endl;
	{
		Intern	intern;

		AForm *form = intern.makeForm("shrubbery creation", "kojwatan");
		std::cout << *form << std::endl;
		delete form;
	}
	std::cout << std::endl;
	std::cout << "Intern makeForm RobotomyRequestForm TEST========" << std::endl;
	{
		Intern	intern;

		AForm *form = intern.makeForm("robotomy request", "kojwatan");
		std::cout << *form << std::endl;
		delete form;
	}
	std::cout << std::endl;
	std::cout << "Intern makeForm PresidentialPardonForm TEST========" << std::endl;
	{
		Intern	intern;

		AForm *form = intern.makeForm("presidential pardon", "kojwatan");
		std::cout << *form << std::endl;
		delete form;
	}
	std::cout << std::endl;
	std::cout << "Intern makeForm No Form TEST========" << std::endl;
	{
		Intern	intern;

		AForm *form = intern.makeForm("residential pardon", "kojwatan");
		std::cout << (form == nullptr ? "null" : "not null") << std::endl;
		delete form;
	}
	std::cout << std::endl;
}
