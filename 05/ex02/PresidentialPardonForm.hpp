#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	AForm;

class	PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm	&other);
		~PresidentialPardonForm(void);

		std::string	getTarget(void) const;
		void	execute(const Bureaucrat &executor) const;

	private:
		const std::string	_target;
};

#endif
