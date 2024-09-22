#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreaionForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &src)
{
	out << "Form Name: " << src.getName() << ",Grade To Sign: " << src.getGradeSign() << ",Grade To Execute: " << src.getGradeExe() << ",Target: " << src.getTarget();
	return (out);
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
			outfile.close();
			return ;
		}	
	}
}