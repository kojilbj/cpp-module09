#ifndef ROBOTMYREQESTFORM_HPP
#define ROBOTMYREQESTFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

class	AForm;
class	Bureacrat;

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);

		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		std::string	getTarget(void) const;
		void	execute(Bureaucrat const &executor) const;

	private:
		const std::string	_target;
};

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &form);

#endif
