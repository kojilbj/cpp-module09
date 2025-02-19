#include <iostream>
#include <ctime>

#include "PmergeMe.hpp"


void	printBefore(char *av[])
{
	std::cout << "Before:";
	for (size_t i = 0; av[i] != NULL; i++)
		std::cout << " " << av[i];
	std::cout << std::endl;
}

void	printAfter(char *av[])
{
	std::cout << "After: ";
	PmergeMe::print(PmergeMe::DequeProcess(av));
}

void	printListRange(char *av[])
{
	size_t	i;

	std::cout << "Time to process a range of ";
	for (i = 0; av[i] != NULL; i++)
		;
	std::cout << i << " elements with std::list";

}

void	printDequeRange(char *av[])
{
	size_t	i;

	std::cout << "Time to process a range of ";
	for (i = 0; av[i] != NULL; i++)
		;
	std::cout << i << " elements with std::deque";
}

void	printTime(clock_t start, clock_t end)
{
	double duration;

	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << " : " << duration << " us" << std::endl;
}

int	main(int ac, char *argv[])
{
	clock_t	start;
	clock_t	end;

	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 0;
	}
	//TO DO マイナスが来た時の判定
	printBefore(&argv[1]);
	printAfter(&argv[1]);

	printListRange(&argv[1]);

	start = clock();
	std::list<int>	list = PmergeMe::ListProcess(&argv[0]);
	end = clock();
	printTime(start, end);

	printDequeRange(&argv[1]);

	start = clock();
	std::deque<int>	deque = PmergeMe::DequeProcess(&argv[1]);
	end = clock();
	printTime(start, end);
}
