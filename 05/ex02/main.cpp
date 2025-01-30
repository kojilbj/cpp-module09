#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "==========ShrubberyCreationForm TEST==========" << std::endl;
	{
		std::cout << "ShrubberyCreationForm Defualt Constructor TEST==========" << std::endl;
		{
			ShrubberyCreationForm	sf;
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "ShrubberyCreationForm Constructor TEST==========" << std::endl;
		{
			ShrubberyCreationForm	sf("kojwatan");
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "ShrubberyCreationForm Copy Operator TEST==========" << std::endl;
		{
			ShrubberyCreationForm	sf1("koji");
			ShrubberyCreationForm	sf2("watan");
			sf1 = sf2;
			std::cout << sf1 << std::endl;
		}
		std::cout << std::endl;
		std::cout << "ShrubberyCreationForm Sign SUCCESS TEST==========" << std::endl;
		{
			ShrubberyCreationForm	sf("koji");
			Bureaucrat	br("koji", 145);
			br.signForm(sf);
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "ShrubberyCreationForm Sign Failiare TEST==========" << std::endl;
		{
			ShrubberyCreationForm	sf("koji");
			Bureaucrat	br("koji", 146);
			br.signForm(sf);
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "ShrubberyCreationForm Execute SUCCESS TEST==========" << std::endl;
		{
			ShrubberyCreationForm	sf("koji");
			Bureaucrat	br("koji", 137);
			br.signForm(sf);
			br.executeForm(sf);
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "ShrubberyCreationForm Execute Failiare TEST==========" << std::endl;
		{
			ShrubberyCreationForm	sf1("koji");
			ShrubberyCreationForm	sf2("koji");
			Bureaucrat	br("koji", 138);
			br.signForm(sf1);
			br.executeForm(sf1);
			std::cout << sf1 << std::endl;
			br.executeForm(sf2);
			std::cout << sf2 << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "==========RobotomyRequestForm TEST==========" << std::endl;
	{
		std::cout << "RobotomyRequestForm Defualt Constructor TEST==========" << std::endl;
		{
			RobotomyRequestForm	sf;
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "RobotomyRequestForm Constructor TEST==========" << std::endl;
		{
			RobotomyRequestForm	sf("kojwatan");
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "RobotomyRequestForm Copy Operator TEST==========" << std::endl;
		{
			RobotomyRequestForm	sf1("koji");
			RobotomyRequestForm	sf2("watan");
			sf1 = sf2;
			std::cout << sf1 << std::endl;
		}
		std::cout << std::endl;
		std::cout << "RobotomyRequestForm Sign SUCCESS TEST==========" << std::endl;
		{
			RobotomyRequestForm	sf("koji");
			Bureaucrat	br("koji", 72);
			br.signForm(sf);
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "RobotomyRequestForm Sign Failiare TEST==========" << std::endl;
		{
			RobotomyRequestForm	sf("koji");
			Bureaucrat	br("koji", 73);
			br.signForm(sf);
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "RobotomyRequestForm Execute SUCCESS TEST==========" << std::endl;
		{
			RobotomyRequestForm	sf("koji");
			Bureaucrat	br("koji", 45);
			br.signForm(sf);
			br.executeForm(sf);
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "RobotomyRequestForm Execute Failiare TEST==========" << std::endl;
		{
			RobotomyRequestForm	sf1("koji");
			RobotomyRequestForm	sf2("koji");
			Bureaucrat	br("koji", 46);
			br.signForm(sf1);
			br.executeForm(sf1);
			std::cout << sf1 << std::endl;
			br.executeForm(sf2);
			std::cout << sf2 << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "==========PresidentialPardonForm TEST==========" << std::endl;
	{
		std::cout << "PresidentialPardonForm Defualt Constructor TEST==========" << std::endl;
		{
			PresidentialPardonForm	sf;
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "PresidentialPardonForm Constructor TEST==========" << std::endl;
		{
			PresidentialPardonForm	sf("kojwatan");
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "PresidentialPardonForm Copy Operator TEST==========" << std::endl;
		{
			PresidentialPardonForm	sf1("koji");
			PresidentialPardonForm	sf2("watan");
			sf1 = sf2;
			std::cout << sf1 << std::endl;
		}
		std::cout << std::endl;
		std::cout << "PresidentialPardonForm Sign SUCCESS TEST==========" << std::endl;
		{
			PresidentialPardonForm	sf("koji");
			Bureaucrat	br("koji", 25);
			br.signForm(sf);
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "PresidentialPardonForm Sign Failiare TEST==========" << std::endl;
		{
			PresidentialPardonForm	sf("koji");
			Bureaucrat	br("koji", 26);
			br.signForm(sf);
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "PresidentialPardonForm Execute SUCCESS TEST==========" << std::endl;
		{
			PresidentialPardonForm	sf("koji");
			Bureaucrat	br("koji", 5);
			br.signForm(sf);
			br.executeForm(sf);
			std::cout << sf << std::endl;
		}
		std::cout << std::endl;
		std::cout << "PresidentialPardonForm Execute Failiare TEST==========" << std::endl;
		{
			PresidentialPardonForm	sf1("koji");
			PresidentialPardonForm	sf2("koji");
			Bureaucrat	br("koji", 7);
			br.signForm(sf1);
			br.executeForm(sf1);
			std::cout << sf1 << std::endl;
			br.executeForm(sf2);
			std::cout << sf2 << std::endl;
		}
		std::cout << std::endl;
	}
}
