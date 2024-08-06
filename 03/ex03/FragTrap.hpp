#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap: public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(const FragTrap& fragtrap);
		FragTrap&	operator=(const FragTrap& fragtrap);

		void	highFiveGuys(void);

	private:

};

#endif