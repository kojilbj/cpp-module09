#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class	Intern
{
public:
	Intern(void);
	Intern(const Intern &src);

	~Intern(void);

	Intern	&operator=(const Intern &other);

	AForm	*makeForm(const std::string &name, const std::string &target) const;

private:
	AForm	*makeShrubberyCreationForm(const std::string &target) const;
	AForm	*makeRobotomyRequestForm(const std::string &target) const;
	AForm	*makePresidentialPardonForm(const std::string &target) const;
};
