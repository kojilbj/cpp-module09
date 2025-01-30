#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Default Constructor Test==========" << std::endl;
	{
		Bureaucrat	bu;
		std::cout << bu << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Original Constructor Test==========" << std::endl;
	{
		Bureaucrat	bu("kojwatan", 120);
		std::cout << bu << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Copy Constructor Test==========" << std::endl;
	{
		Bureaucrat	bu1("kojwatan", 120);
		Bureaucrat	bu2(bu1);
		std::cout << bu2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Copy Operator Test==========" << std::endl;
	{
		Bureaucrat	bu1("koji", 120);
		Bureaucrat	bu2("watanabe", 1);

		std::cout << bu1 << std::endl;
		std::cout << bu2 << std::endl;
		bu1 = bu2;
		std::cout << bu1 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Constructor GradeTooHigh Test==========" << std::endl;
	{
		try
		{
			Bureaucrat	bu("kojwatan", 0);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "Constructor GradeTooLow Test==========" << std::endl;
	{
		try
		{
			Bureaucrat	bu("kojwatan", 160);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "Inclement Method Test==========" << std::endl;
	{
		try
		{
			Bureaucrat	bu("kojwatan", 2);
			std::cout << bu << std::endl;
			bu.upGrade();
			std::cout << bu << std::endl;
			bu.upGrade();
			std::cout << bu << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat	bu("kojwatan", 149);
			std::cout << bu << std::endl;
			bu.downGrade();
			std::cout << bu << std::endl;
			bu.downGrade();
			std::cout << bu << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
