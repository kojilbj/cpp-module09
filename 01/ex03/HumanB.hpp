
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "./Weapon.hpp"

class	HumanB
{
	public:
		HumanB(const std::string& new_name);
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon& new_weapon);

	private:
		std::string	name;
		Weapon*	weapon;

};

#endif