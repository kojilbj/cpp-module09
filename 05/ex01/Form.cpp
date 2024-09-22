#include "Form.hpp"

Form::Form(const std::string &name, int grade_sign, int grade_exe): _name(name), _grade_sign(grade_sign), _grade_exe(grade_exe)
{
	std::cout << "Form Constructor Called" << std::endl;
	_is_signed = false;
	if (_grade_sign > 150 || _grade_exe > 150)
		throw(GradeTooLowException());
	if (_grade_sign < 1 || _grade_exe < 1)
		throw(GradeTooHighException());
}

Form::Form(const Form &form): _name(form.getName()), _grade_sign(form.getGradeSign()), _grade_exe(form.getGradeExe())
{
	_is_signed = form.getIsSigned();
}

Form::~Form(void)
{
	std::cout << "Form Destructor Called" << std::endl;
}

Form	&Form::operator=(const Form &form)
{
	if (this == &form)
		return(*this);
	this->_is_signed = form.getIsSigned();
	return (*this);
}

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_is_signed);
}

int	Form::getGradeSign(void) const
{
	return (_grade_sign);
}

int	Form::getGradeExe(void) const
{
	return (_grade_exe);
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLow");
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHigh");
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() < _grade_sign)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", sign grade " << form.getGradeSign();
	out << ", execution grade " << form.getGradeExe();
	return (out);
}
