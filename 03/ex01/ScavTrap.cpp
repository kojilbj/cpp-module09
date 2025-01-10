#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attack_damage_ = 20;
	this->guard_gate_mode_ = false;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->guard_gate_mode_ = other.guard_gate_mode_;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->hit_points_ = other.hit_points_;
	this->energy_points_ = other.energy_points_;
	this->attack_damage_ = other.attack_damage_;
	this->guard_gate_mode_ = other.guard_gate_mode_;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	if (this->guard_gate_mode_ == false)
	{
		std::cout << this->name_ << " turn into guard gate mode" << std::endl;
		this->guard_gate_mode_ = true;
	}
	else
		std::cout << this->name_ << " is already guard gate mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energy_points_ == 0)
	{
		std::cout << name_ << " has no Energy points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name_ << " attacks " << target << " " << this->attack_damage_ << " caused points damage" << std::endl;
	this->energy_points_--;
}
