#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main(int ac, char* av[])
{
	if (ac != 2)
	{
		std::cerr << "Error: invalid arguments." << std::endl;
		return 0;
	}
	try
	{
		std::string fomula(av[1]);
		std::stringstream ss(fomula);
		std::cout << RPN::calculate(ss) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
