#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) 
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->hit_points_ = other.hit_points_;
	this->energy_points_ = other.energy_points_;
	this->attack_damage_ = other.attack_damage_;
	return *this;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "HighFive Guys!!" << std::endl;
}
