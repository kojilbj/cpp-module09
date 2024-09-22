#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm(const std::string &name, int grade_sign = 150, int grade_exe = 150);
		AForm(const AForm &src);
		~AForm();
		AForm	&operator=(const AForm &aform);

		//Getters
		std::string	getName(void) const;
		int	getGradeSign(void) const;
		int	getGradeExe(void) const;
		bool	getIsSigned(void) const;

		void	beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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
		const int	_grade_sign;
		const int	_grade_exe;
		bool	_is_signed;
		

};

std::ostream	&operator<<(std::ostream &out, const AForm &aform);

#endif