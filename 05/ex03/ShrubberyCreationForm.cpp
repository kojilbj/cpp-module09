#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreaionForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreaionForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Copy Operator Called" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::fstream	outfile;
	std::string	target_file;

	if (this->getIsSigned() == true)
	{
		if (this->getGradeExe() < executor.getGrade())
			throw (AForm::GradeTooLowException());
		target_file = _target + "_shrubbery";
		outfile.open(target_file, std::fstream::out);
		if (outfile.is_open() == false)
		{
			std::cerr << "open: " << std::strerror(errno) << std::endl;
			return ;
		}
		else
		{
			outfile << "       ccee88oo\n";
			outfile << "    C8O8O8Q8PoOb o8oo\n";
			outfile << " dOB69QO8PdUOpugoO9bD\n";
			outfile << "CgggbU8OU qOp qOdoUOdcb\n";
			outfile << "    6OuU  /p u gcoUodpP\n";
			outfile << "      \\\\//  /douUP\n";
			outfile << "        \\\\////\n";
			outfile << "         |||/\\\n";
			outfile << "         |||\\/\n";
			outfile << "         |||||\n";
			outfile << "   .....//||||\\....\n";
		}
		outfile.close();
	}
	else
	{
		throw (std::runtime_error(this->getName() + " is not signed."));
	}
}

std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
	const AForm *formPtr;

	formPtr = &form;
	out << *formPtr;
	out << ", target " << form.getTarget();
	return out;
}
