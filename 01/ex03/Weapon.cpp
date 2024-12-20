#include "./Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& new_type)
{
	type = new_type;
}

Weapon::Weapon(void)
{
	type = std::string("");
}

Weapon::~Weapon(void)
{

}

const std::string&	Weapon::getType(void)
{
	return type;
}

void	Weapon::setType(const std::string& new_type)
{
	type = new_type;
}