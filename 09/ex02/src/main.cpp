#include <iostream>

#include "PmergeMe.hpp"

int	main(void)
{
	PmergeMe	pm;

	std::list<int>	list = pm.ListProcess();
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::deque<int>	deque = pm.DequeProcess();
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
