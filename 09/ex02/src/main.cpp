#include <iostream>

#include "RPN.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2)
		return 0;
	try
	{
		std::cout << RPN::Calculate(av[1]) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error" << std::endl;
	}
	return 0;
}
