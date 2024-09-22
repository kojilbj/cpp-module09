#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

class	AForm;
class	Bureacrat;

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);

		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		std::string	getTarget(void) const;
		void	execute(Bureaucrat const &executor) const;

	private:
		const std::string	_target;
};

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &src);