#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class	Form;

class	Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat(void);
	Bureaucrat	&operator=(const Bureaucrat &other);

	std::string	getName(void) const;
	int		getGrade(void) const;

	void		upGrade(void);
	void		downGrade(void);
	void		signForm(Form &form) const;

	class	 GradeTooLowException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};
		
	class	GradeTooHighException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

private:
	const std::string	_name;
	int			_grade;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
