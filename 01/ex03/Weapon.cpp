#include "./Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string new_type)
{
	type = new_type;
}

Weapon::Weapon(void)
{
	type = std::string();
}

Weapon::~Weapon(void)
{

}

const std::string&	Weapon::getType(void)
{
	const std::string&	str = type;
	return (str);
}

void	Weapon::setType(std::string new_type)
{
	type = new_type;
}