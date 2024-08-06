#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name): name_(name)
{
	std::cout << "Constructor called" << std::endl;
	hit_points_ = 10;
	energy_points_ = 10;
	attack_damage_ = 0;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap): name_(claptrap.name_)
{
	this->hit_points_ = claptrap.hit_points_;
	this->energy_points_ = claptrap.hit_points_;
	this->attack_damage_ = claptrap.attack_damage_;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& claptrap)
{
	this->hit_points_ = claptrap.hit_points_;
	this->energy_points_ = claptrap.hit_points_;
	this->attack_damage_ = claptrap.attack_damage_;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points_ == 0)
	{
		std::cout << name_ << " has no Energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name_ << "attacks " << target << " " << this->attack_damage_ << " caused points damage" << std::endl;
	this->energy_points_--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points_ > amount)
		hit_points_ -= amount;
	else if (this->hit_points_ != 0)
		hit_points_ = 0;
	else
	{
		std::cout << "ClapTrap is already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name_ << "take " << amount << " points damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name_ << "be reapaired" << std::endl;
	if (energy_points_ == 0)
	{
		std::cout << name_ << " has no Energy points" << std::endl;
		return ;
	}
	hit_points_ += amount;
	energy_points_--;
}
