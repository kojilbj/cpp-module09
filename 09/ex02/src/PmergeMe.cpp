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

std::list<int>	PmergeMe::ListProcess()
{
	std::list<int>	list;

	return list;
}

std::deque<int>	PmergeMe::DequeProcess()
{
	std::deque<int>	deque;

	return deque;
}
