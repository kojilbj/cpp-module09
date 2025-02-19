#include <sstream>
#include <algorithm>
#include <iostream>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &)
{
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &)
{
	return *this;
}

PmergeMe::~PmergeMe()
{
}


std::list<int>	PmergeMe::ListProcess(char *av[])
{
	std::list<int>	list;

	for (size_t i = 0; av[i] != NULL; i++)
	{
		list.push_back(std::atoi(av[i]));
	}
	FordJohnsonSort(list);
	return list;
}

void	PmergeMe::FordJohnsonSort(std::list<int>& list)
{
	if (list.size() <= 1)
		return ;
	std::list<int> winner, loser;

	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::list<int>::iterator next = it;

		next++;
		if (next == list.end())
		{
			winner.push_back(*it);
			break ;
		}
		if (*it >= *next)
		{
			winner.push_back(*it);
			loser.push_back(*next);
		}
		else
		{
			winner.push_back(*next);
			loser.push_back(*it);
		}
		it = next;
	}
	FordJohnsonSort(winner);
	for (std::list<int>::iterator it = loser.begin(); it != loser.end(); it++)
	{
		std::list<int>::iterator insertPos = std::lower_bound(winner.begin(), winner.end(), *it);
		winner.insert(insertPos, *it);
	}
	list = winner;
}

std::deque<int>	PmergeMe::DequeProcess(char *av[])
{
	std::deque<int>	deque;

	for (size_t i = 0; av[i] != NULL; i++)
	{
		deque.push_back(std::atoi(av[i]));
	}
	FordJohnsonSort(deque);
	return deque;
}

void	PmergeMe::FordJohnsonSort(std::deque<int>& deque)
{
	if (deque.size() <= 1)
		return ;
	std::deque<int> winner, loser;

	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it += 2)
	{
		if (it + 1 == deque.end())
		{
			winner.push_back(*it);
			break ;
		}
		if (*it >= *(it + 1))
		{
			winner.push_back(*it);
			loser.push_back(*(it + 1));
		}
		else
		{
			winner.push_back(*(it + 1));
			loser.push_back(*it);
		}
	}
	FordJohnsonSort(winner);
	for (std::deque<int>::iterator it = loser.begin(); it != loser.end(); it++)
	{
		std::deque<int>::iterator insertPos = std::lower_bound(winner.begin(), winner.end(), *it);
		winner.insert(insertPos, *it);
	}
	deque = winner;
}
