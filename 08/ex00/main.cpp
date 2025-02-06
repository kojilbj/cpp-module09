#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> container;

	container.push_back(1);
	container.push_back(2);
	container.push_back(3);

	try
	{
		std::cout << *(::easyfind(container, 2)) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << *(::easyfind(container, 9)) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
