#include <string>
#include <iostream>
#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = std::string(name);
}

Zombie::Zombie(void)
{
	_name = std::string("");
}

Zombie::~Zombie(void)
{
	std::cout << _name << ": Long live the king!" << std::endl;
}