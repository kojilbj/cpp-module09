#include "Form.hpp"

Form::Form(void): _name("default"), _grade_sign(150), _grade_exe(150), _is_signed(false)
{
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(const std::string &name, int grade_sign, int grade_exe): _name(name), _grade_sign(grade_sign), _grade_exe(grade_exe), _is_signed(false)
{
	std::cout << "Form Constructor Called" << std::endl;
	if (_grade_sign > 150 || _grade_exe > 150)
		throw(GradeTooLowException());
	if (_grade_sign < 1 || _grade_exe < 1)
		throw(GradeTooHighException());
}

Form::Form(const Form &other): _name(other._name), _grade_sign(other._grade_sign), _grade_exe(other._grade_exe), _is_signed(other._is_signed)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form Destructor Called" << std::endl;
}

Form	&Form::operator=(const Form &other)
{
	std::cout << "Form Copy Operator Called" << std::endl;
	if (this == &other)
		return *this;
	this->_is_signed = other._is_signed;
	return *this;
}

std::string	Form::getName(void) const
{
	return _name;
}

bool	Form::getIsSigned(void) const
{
	return _is_signed;
}

int	Form::getGradeSign(void) const
{
	return _grade_sign;
}

int	Form::getGradeExe(void) const
{
	return _grade_exe;
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return "GradeTooLow";
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return "GradeTooHigh";
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_sign)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", sign grade " << form.getGradeSign();
	out << ", execution grade " << form.getGradeExe();
	out << ", is signed: " << (form.getIsSigned() ? "YES" : "NO");
	return out;
}
