#include <ctime>
#include <iostream>
#include <exception>

#include "PmergeMe.hpp"

void printBefore(char* av[])
{
	std::cout << "Before:";
	for (size_t i = 1; av[i] != NULL; i++)
		std::cout << " " << av[i];
	std::cout << std::endl;
}

void printAfter(char* av[])
{
	std::cout << "After: ";
	PmergeMe::print(PmergeMe::DequeProcess(av));
}

void printListRange(char* av[])
{
	size_t i;

	std::cout << "Time to process a range of ";
	for (i = 0; av[i] != NULL; i++)
		;
	std::cout << i << " elements with std::list";
}

void printDequeRange(char* av[])
{
	size_t i;

	std::cout << "Time to process a range of ";
	for (i = 0; av[i] != NULL; i++)
		;
	std::cout << i << " elements with std::deque";
}

void printTime(clock_t start, clock_t end)
{
	double duration;

	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << " : " << duration << " us" << std::endl;
}

int main(int ac, char* argv[])
{
	clock_t start;
	clock_t end;

	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 0;
	}
	try
	{
		for (size_t i = 1; argv[i] != NULL; i++)
		{
			PmergeMe::toInt(argv[i]);
		}
		printBefore(argv);
		printAfter(argv);

		printListRange(&argv[1]);

		start = clock();
		std::list<int> list = PmergeMe::ListProcess(argv);
		end = clock();
		printTime(start, end);
		std::cout << PmergeMe::compareCount << std::endl;

		printDequeRange(&argv[1]);

		start = clock();
		std::deque<int> deque = PmergeMe::DequeProcess(argv);
		end = clock();
		printTime(start, end);
		std::cout << PmergeMe::compareCount << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
