#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "Form Default Constructor Test==========" << std::endl;
	{
		Form	fm;

		std::cout << fm << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Form Constructor Test==========" << std::endl;
	{
		Form	fm("task1", 50, 60);

		std::cout << fm << std::endl;
	}

	std::cout << "Form Copy Constructor Test==========" << std::endl;
	{
		Form	fm1("task1", 50, 60);
		Form	fm2("task2", 11, 110);

		Bureaucrat("kojwatan", 1).signForm(fm1);
		std::cout << fm1 << std::endl;
		std::cout << fm2 << std::endl;
		fm2 = fm1;
		std::cout << fm2 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Form GradeTooHigh Test==========" << std::endl;
	{
		try
		{
			std::cout << "Grade to Sign" << std::endl;
			Form fm("task1", -1, 1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "Grade to Exec" << std::endl;
			Form fm("task1", 1, -1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;


	std::cout << "Form GradeTooLow Test==========" << std::endl;
	{
		try
		{
			std::cout << "Grade to Sign" << std::endl;
			Form fm("task1", 151, 1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "Grade to Exec" << std::endl;
			Form fm("task1", 1, 151);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "Sign Test==========" << std::endl;
	{
		Form	fm("task1", 1, 1);
		Bureaucrat	br("kojwatan", 1);

		br.signForm(fm);
		std::cout << fm << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Too Low Grade to Sign Test==========" << std::endl;
	{
		Form	fm("task1", 1, 1);
		Bureaucrat	br("kojwatan", 2);

		br.signForm(fm);
		std::cout << fm << std::endl;
	}
	std::cout << std::endl;
}
