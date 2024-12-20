
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& new_name) 
{
	name = new_name;	
	weapon = nullptr; 
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	if (weapon != nullptr)
		std::cout << name << " attacks with their " << weapon->getType();
	else
		std::cout << name << " has no weapon"; 
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& new_weapon)
{
	weapon = &new_weapon;
}