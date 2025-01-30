#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class	Bureaucrat
{
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat(void);
	Bureaucrat	&operator=(const Bureaucrat &other);

	std::string	getName(void) const;
	int		getGrade(void) const;

	void		upGrade(void);
	void		downGrade(void);

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
