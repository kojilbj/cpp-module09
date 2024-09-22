#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	*bu;
	try
	{
		bu = new Bureaucrat("koji", 1111);
	}
	catch(Bureaucrat::GradeTooLowException	&e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException	&e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bu = new Bureaucrat("koji", 11);
		while (1)
			bu->upGrade();
	}
	catch(Bureaucrat::GradeTooLowException	&e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException	&e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete bu;
	try
	{
		bu = new Bureaucrat("koji", 11);
		while (1)
			bu->downGrade();
	}
	catch(Bureaucrat::GradeTooLowException	&e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException	&e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *bu;
	delete bu;
}
