#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Constructor called" << std::endl;
	if (getGrade() < 1)
		throw(GradeTooHighException());
	if (getGrade() > 150)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (&other == this)
		return *this;
	this->_grade = other._grade;
	return *this;
}


std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::upGrade(void)
{
	if (_grade == 1)
		throw(GradeTooHighException());
	_grade = _grade - 1;
}

void	Bureaucrat::downGrade(void)
{
	if (_grade == 150)
		throw(GradeTooLowException());
	_grade = _grade + 1;
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "GradeTooLow";
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "GradeTooHigh";
}

	std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << "[SUCCESS] " << *this << " executed " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "[FAILIARE]" << *this << " could'nt execute " << form << std::endl;
		std::cout << "[Error Content]" << e.what() << std::endl;
	}
}
