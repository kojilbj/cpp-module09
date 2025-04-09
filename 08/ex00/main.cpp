#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>

int	main(void)
{
	{
		std::vector<int> container;

		container.push_back(1);
		container.push_back(2);
		container.push_back(3);

		std::cout << "vector: ";
		for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;
		// Test for Head Element
		std::cout << *(::easyfind(container, 1)) << std::endl;

		// Test for Middle Element
		std::cout << *(::easyfind(container, 2)) << std::endl;

		// Test for Last Element
		std::cout << *(::easyfind(container, 3)) << std::endl;

		// Test for Uncontains Element
		if (::easyfind(container, 9) == container.end())
			std::cout << "Not found" << std::endl;
	}

	{
		std::deque<int> container;

		container.push_back(1);
		container.push_back(2);
		container.push_back(3);

		std::cout << "deque: ";
		for (std::deque<int>::iterator it = container.begin(); it != container.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;
		// Test for Head Element
		std::cout << *(::easyfind(container, 1)) << std::endl;

		// Test for Middle Element
		std::cout << *(::easyfind(container, 2)) << std::endl;

		// Test for Last Element
		std::cout << *(::easyfind(container, 3)) << std::endl;

		// Test for Uncontains Element
		if (::easyfind(container, 9) == container.end())
			std::cout << "Not found" << std::endl;
	}
}
