#include <iostream>
#include "./ClapTrap.hpp"

int	main(void)
{
	ClapTrap	cl("koji");

	std::cout << "---------- action ---------" << std::endl;
	for (size_t i = 0; i < 6; i++)
	{
		cl.attack("watanabe");
		cl.takeDamage(5);
		cl.beRepaired(4);
	}
	cl.takeDamage(5);
	std::cout << "-------------------" << std::endl;

	std::cout << "---------- Copy Constructor---------" << std::endl;
	ClapTrap	cl2(cl);
	cl2.beRepaired(5);
	std::cout << "-------------------" << std::endl;

	std::cout << "---------- Assignment Operator ---------" << std::endl;
	ClapTrap	cl3("watanabe");
	cl3.beRepaired(5);
	cl3 = cl2;
	cl3.beRepaired(5);
	std::cout << "-------------------" << std::endl;
}
