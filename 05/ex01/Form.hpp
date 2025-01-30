#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
public:
	Form(void);
	Form(const std::string &name, int grade_sign, int grade_exe);
	Form(const Form &other);
	~Form(void);
	Form	&operator=(const Form &form);

	//Getters
	std::string	getName(void) const;
	int	getGradeSign(void) const;
	int	getGradeExe(void) const;
	bool	getIsSigned(void) const;

	void	beSigned(const Bureaucrat &bureaucrat);

	class	GradeTooHighException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

	class	GradeTooLowException: public std::exception
	{
	public:
		const char	*what(void) const throw();
	};

private:
	const std::string	_name;
	const int		_grade_sign;
	const int		_grade_exe;
	bool			_is_signed;
		

};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif
