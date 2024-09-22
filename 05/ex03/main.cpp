#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	intern;
	AForm	*form;

	form = intern.makeForm("shrubbery creation", "koji");
	if (form == nullptr)
		std::cout << "NULL" << std::endl;
	else
		std::cout << form->getGradeSign() << std::endl;
	delete form;
}