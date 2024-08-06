#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		DiamondTrap(const DiamondTrap& diamondtrap);

		DiamondTrap&	operator=(const DiamondTrap& diamondtrap);

		void	attack(const std::string &target);
		void	whoAmI(void);

	private:
		std::string	name_;
};

#endif