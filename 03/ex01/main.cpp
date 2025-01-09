#include <iostream>
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap st("koji");
	std::cout << "---------- action ---------" << std::endl;
	for (size_t i = 0; i < 26; i++)
	{
		st.attack("watanabe");
		st.takeDamage(50);
		st.beRepaired(49);
	}
	st.takeDamage(50);
	std::cout << "-------------------" << std::endl;
	st.guardGate();

	std::cout << "---------- Copy Constructor---------" << std::endl;
	ScavTrap	st2(st);
	st2.beRepaired(10);
	std::cout << "-------------------" << std::endl;

	std::cout << "---------- Assignment Operator ---------" << std::endl;
	ScavTrap	st3("watanabe");
	st3.beRepaired(5);
	st3 = st2;
	st3.beRepaired(5);
	std::cout << "-------------------" << std::endl;
}
