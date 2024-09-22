#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form	*form;

	try
	{
		form = new Form("task1", 3);
		Bureaucrat("koji", 1110).signForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << *form << std::endl;
	delete form;
}
