#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	ShrubberyCreationForm	*form;
	Bureaucrat	*b;
	form = new ShrubberyCreationForm("koji");
	b = new Bureaucrat("koji", 1);

	try
	{
		b->signForm(*form);
		b->executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *form << std::endl;
}
