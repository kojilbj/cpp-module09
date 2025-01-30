#include "AForm.hpp"

AForm::AForm(void): _name("default"), _grade_sign(150), _grade_exe(150), _is_signed(false)
{
	std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::AForm(const std::string &name, int grade_sign, int grade_exe): _name(name), _grade_sign(grade_sign), _grade_exe(grade_exe), _is_signed(false)
{
	std::cout << "AForm Constructor Called" << std::endl;
	if (_grade_sign > 150 || _grade_exe > 150)
		throw(GradeTooLowException());
	if (_grade_sign < 1 || _grade_exe < 1)
		throw(GradeTooHighException());
}

AForm::AForm(const AForm &aform): _name(aform.getName()), _grade_sign(aform.getGradeSign()), _grade_exe(aform.getGradeExe())
{
	_is_signed = aform.getIsSigned();
}

AForm::~AForm(void)
{
	std::cout << "AForm Destructor Called" << std::endl;
}

AForm	&AForm::operator=(const AForm &aform)
{
	if (this == &aform)
		return(*this);
	this->_is_signed = aform.getIsSigned();
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_is_signed);
}

int	AForm::getGradeSign(void) const
{
	return (_grade_sign);
}

int	AForm::getGradeExe(void) const
{
	return (_grade_exe);
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLow");
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHigh");
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_sign)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, const AForm &aform)
{
	out << aform.getName() << ", sign grade " << aform.getGradeSign();
	out << ", execution grade " << aform.getGradeExe();
	out << ", is signed: " << (aform.getIsSigned() ? "YES" : "NO");
	return (out);
}
