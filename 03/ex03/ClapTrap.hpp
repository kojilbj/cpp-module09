#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class	ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& claptrap);
		~ClapTrap(void);

		ClapTrap& operator=(const ClapTrap& claptrap);

		void	attack(const std::string& target);	
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string	name_;
		int	hit_points_;
		int	energy_points_;
		int	attack_damage_;
};

#endif