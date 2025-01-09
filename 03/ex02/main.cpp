#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap	ft("koji");
	std::cout << "---------- action ---------" << std::endl;
	for (size_t i = 0; i < 51; i++)
	{
		ft.attack("watanabe");
		ft.takeDamage(50);
		ft.beRepaired(49);
	}
	ft.takeDamage(50);
	std::cout << "-------------------" << std::endl;
	ft.highFiveGuys();

	std::cout << "---------- Copy Constructor---------" << std::endl;
	FragTrap	ft2(ft);
	ft2.beRepaired(10);
	std::cout << "-------------------" << std::endl;

	std::cout << "---------- Assignment Operator ---------" << std::endl;
	FragTrap	ft3("watanabe");
	ft3.beRepaired(5);
	ft3 = ft2;
	ft3.beRepaired(5);
	std::cout << "-------------------" << std::endl;
}
