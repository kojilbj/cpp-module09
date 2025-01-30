#ifndef SHRUBBERYCREATIONFROM_HPP
#define SHRUBBERYCREATIONFROM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	AForm;
class	Bureaucrat;

class	ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);

		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		const std::string	_target;


		std::string	getTarget(void) const;

		void	execute(Bureaucrat const &executor) const;

	private:
};

std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &form);

#endif
