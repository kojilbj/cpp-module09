#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap& fragtrap): ClapTrap(fragtrap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& fragtrap) 
{
	std::cout << "FragTrap assign called" << std::endl;
	if (this != &fragtrap)
		ClapTrap::operator=(fragtrap);
	return (*this);
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "HighFive Guys!!" << std::endl;
}
