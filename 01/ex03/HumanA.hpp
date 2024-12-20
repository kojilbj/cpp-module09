#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "./Weapon.hpp"

class	HumanA
{
	public:
		HumanA(const std::string& new_name, Weapon& new_weapon);
		~HumanA(void);

		void	attack(void);

	private:
		std::string	name;
		Weapon&	weapon;
};

#endif