#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	_grade = grade;
	std::cout << "Bureaucrat Constructor called" << std::endl;
	if (getGrade() < 1)
		throw(GradeTooHighException());
	if (getGrade() > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat): _name(bureaucrat.getName())
{
	this->_grade = bureaucrat.getGrade();
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (&bureaucrat == this)
		return (*this);
	this->_grade = bureaucrat.getGrade();
	return (*this);
}


std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::upGrade(void)
{
	_grade = (getGrade() - 1);
	if (getGrade() < 1)
		throw(GradeTooHighException());
}

void	Bureaucrat::downGrade(void)
{
	_grade = (getGrade() + 1);
	if (getGrade() > 150)
		throw(GradeTooLowException());
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLow");
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHigh");
}

	std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}