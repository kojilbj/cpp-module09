#pragma once

#include "AForm.hpp"

class	AForm;

class	PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm	&src);
		~PresidentialPardonForm(void);

		std::string	getTarget(void) const;
		void	execute(const Bureaucrat &executor) const;

	private:
		const std::string	_target;
};

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &src);
