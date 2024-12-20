#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& new_name, Weapon& new_weapon) : weapon(new_weapon)
{
	name = new_name;
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType();
	std::cout << std::endl;
}
