#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attack_damage_ = 20;
	this->guard_gate_ = false;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap): ClapTrap(scavtrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->guard_gate_ = scavtrap.guard_gate_;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& scavtrap)
{
	std::cout << "ScavTrap assign called" << std::endl;
	this->hit_points_ = scavtrap.hit_points_;
	this->energy_points_ = scavtrap.hit_points_;
	this->attack_damage_ = scavtrap.attack_damage_;
	this->guard_gate_ = scavtrap.guard_gate_;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	if (this->guard_gate_ == false)
	{
		std::cout << this->name_ << " turn into guard gate mode" << std::endl;
		this->guard_gate_ = true;
	}
	else
		std::cout << this->name_ << " is already guard gate mode" << std::endl;
}