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

		Intern	&operator=(const Intern &src);

		AForm	*makeForm(const std::string &nameForm, const std::string &target) const;

	private:
		int	checkFormType(const std::string &nameForm) const;
};