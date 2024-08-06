#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& scavtrap);
		// ScavTrap(const ScavTrap& scavtrap);

		ScavTrap&	operator=(const ScavTrap& scavtrap);

		~ScavTrap(void);

		void	guardGate(void);

	private:
		bool	guard_gate_;
};

#endif