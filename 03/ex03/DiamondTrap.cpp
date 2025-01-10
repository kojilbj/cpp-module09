#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void): ClapTrap("default")
{
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), name_(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap): ClapTrap(diamondtrap) 
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->name_ = diamondtrap.name_;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		this->name_ = src.name_;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ClapTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am ClapTrap: " << ClapTrap::name_;
	std::cout << " DiamondTrap: " << name_ << std::endl;
}
