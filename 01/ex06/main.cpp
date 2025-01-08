#include "Harl.hpp"
#include <iostream>

int	main(int ac, char *av[])
{
	Harl	hrl;

	if (ac != 2)
	{
		std::cout << "Input DEBUG, INFO, WARNING or ERROR" << std::endl;
		return (1);
	}
	hrl.complain(av[1]);
	return (0);
}