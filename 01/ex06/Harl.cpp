#include "./Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl(void)
{

}

Harl::~Harl(void)
{

}

void	Harl::complain(std::string level)
{
	int	i;
	void	(Harl::*funcs[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
		{
			(this->*funcs[0])();
			std::cout << std::endl;
		}
		case 1:
		{
			(this->*funcs[1])();
			std::cout << std::endl;
		}
		case 2:
		{
			(this->*funcs[2])();
			std::cout << std::endl;
		}
		case 3:
		{
			(this->*funcs[3])();
			break;
		}
		default:
		{
			std::cout << "Input DEBUG, INFO, WARNING or ERROR" << std::endl;
			break;
		}
	}
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl; 
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}