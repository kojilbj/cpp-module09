#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

#include "PmergeMe.hpp"

int PmergeMe::compareCount = 0;

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe&) { }

PmergeMe& PmergeMe::operator=(const PmergeMe&)
{
	return *this;
}

PmergeMe::~PmergeMe() { }

std::list<int> PmergeMe::ListProcess(char* av[])
{
	std::list<int> list;

	PmergeMe::compareCount = 0;
	for (size_t i = 1; av[i] != NULL; i++)
	{
		list.push_back(std::atoi(av[i]));
	}
	FordJohnsonSort(list, 1);
	return list;
}

std::deque<int> PmergeMe::DequeProcess(char* av[])
{
	std::deque<int> deque;

	PmergeMe::compareCount = 0;
	for (size_t i = 1; av[i] != NULL; i++)
	{
		deque.push_back(std::atoi(av[i]));
	}
	FordJohnsonSort(deque, 1);
	return deque;
}

size_t PmergeMe::JacobsthalNumber(size_t n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void PmergeMe::FordJohnsonSort(std::list<int>& X, size_t tupleSize)
{
	if (tupleSize < 1)
		throw std::invalid_argument("When firstly call FordJonsonSort, tupleSize should be 1.");
	int pairUnits = X.size() / tupleSize;
	if (pairUnits < 2)
		return;

	bool isOdd =
		(pairUnits % 2 == 1);
	std::list<int>::iterator start = X.begin();
	std::list<int>::iterator last = Advance(X.begin(), tupleSize * pairUnits);
	std::list<int>::iterator end = Advance(last, -(isOdd * tupleSize));

	int skip = 2 * tupleSize;
	for (std::list<int>::iterator it = start; it != end; std::advance(it, skip))
	{
		std::list<int>::iterator currPair = Advance(it, tupleSize - 1);
		std::list<int>::iterator nextPair = Advance(it, tupleSize * 2 - 1);
		if (Compare(nextPair, currPair))
		{
			SwapPair(currPair, tupleSize);
		}
	}
	FordJohnsonSort(X, tupleSize * 2);

	typedef std::list<int>::iterator Iterator;

	std::list<Iterator> main;
	std::list<Iterator> pend;
	main.insert(
		main.end(),
		Advance(X.begin(),
				tupleSize - 1));
	main.insert(
		main.end(),
		Advance(X.begin(),
				tupleSize * 2 - 1));

	for (int i = 4; i <= pairUnits; i += 2)
	{
		pend.insert(pend.end(), Advance(X.begin(), tupleSize * (i - 1) - 1));
		main.insert(main.end(), Advance(X.begin(), tupleSize * i - 1));
	}

	if (isOdd)
	{
		pend.insert(pend.end(), Advance(end, tupleSize - 1));
	}

	if (pend.size() == 0)
		return;

	int prevJacob = JacobsthalNumber(1);
	int insertedCount = 0;
	for (int k = 2;; k++)
	{
		int currJacob = JacobsthalNumber(k);
		int jacobDiff = currJacob - prevJacob;
		int offset = 0;
		if (jacobDiff > static_cast<int>(pend.size()))
			break;
		int insertTime = jacobDiff;
		std::list<Iterator>::iterator pendIt = Advance(pend.begin(), jacobDiff - 1);
		std::list<Iterator>::iterator upperLimitIt =
			Advance(main.begin(), currJacob + insertedCount);
		while (insertTime)
		{
			std::list<Iterator>::iterator insertIt =
				std::upper_bound(main.begin(), upperLimitIt, *pendIt, Compare<Iterator>);
			std::list<Iterator>::iterator inserted = main.insert(insertIt, *pendIt);
			insertTime--;
			pendIt = pend.erase(pendIt);
			std::advance(pendIt, -1);
			offset += std::distance(main.begin(), inserted) == currJacob + insertedCount;
			upperLimitIt = Advance(main.begin(), currJacob + insertedCount - offset);
		}
		prevJacob = currJacob;
		insertedCount += jacobDiff;
		offset = 0;
	}
	for (int i = static_cast<int>(pend.size()) - 1; i >= 0; i--)
	{
		std::list<Iterator>::iterator currPend = Advance(pend.begin(), i);
		std::list<Iterator>::iterator currBound =
			Advance(main.begin(), main.size() - pend.size() + i + isOdd);
		std::list<Iterator>::iterator insertIt =
			std::upper_bound(main.begin(), currBound, *currPend, Compare<Iterator>);
		main.insert(insertIt, *currPend);
	}

	std::list<int> copy;
	for (std::list<Iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		for (size_t i = 0; i < tupleSize; i++)
		{
			Iterator tupleStart = *it;
			std::advance(tupleStart, -tupleSize + i + 1);
			copy.insert(copy.end(), *tupleStart);
		}
	}

	Iterator xIt = X.begin();
	std::list<int>::iterator copyIt = copy.begin();
	while (copyIt != copy.end())
	{
		*xIt = *copyIt;
		xIt++;
		copyIt++;
	}
}

void PmergeMe::FordJohnsonSort(std::deque<int>& X, size_t tupleSize)
{
	if (tupleSize < 1)
		throw std::invalid_argument("When firstly call FordJonsonSort, tupleSize should be 1.");
	int pairUnits = X.size() / tupleSize;
	if (pairUnits < 2)
		return;

	bool isOdd =
		(pairUnits % 2 == 1);
	std::deque<int>::iterator start = X.begin();
	std::deque<int>::iterator last = Advance(X.begin(), tupleSize * pairUnits);
	std::deque<int>::iterator end = Advance(last, -(isOdd * tupleSize));

	int skip = 2 * tupleSize;
	for (std::deque<int>::iterator it = start; it != end; std::advance(it, skip))
	{
		std::deque<int>::iterator currPair = Advance(it, tupleSize - 1);
		std::deque<int>::iterator nextPair = Advance(it, tupleSize * 2 - 1);
		if (Compare(nextPair, currPair))
		{
			SwapPair(currPair, tupleSize);
		}
	}
	FordJohnsonSort(X, tupleSize * 2);

	typedef std::deque<int>::iterator Iterator;

	std::deque<Iterator> main;
	std::deque<Iterator> pend;
	main.insert(
		main.end(),
		Advance(X.begin(),
				tupleSize - 1));
	main.insert(
		main.end(),
		Advance(X.begin(),
				tupleSize * 2 - 1));

	for (int i = 4; i <= pairUnits; i += 2)
	{
		pend.insert(pend.end(), Advance(X.begin(), tupleSize * (i - 1) - 1));
		main.insert(main.end(), Advance(X.begin(), tupleSize * i - 1));
	}

	if (isOdd)
	{
		pend.insert(pend.end(), Advance(end, tupleSize - 1));
	}

	if (pend.size() == 0)
		return;

	int prevJacob = JacobsthalNumber(1);
	int insertedCount = 0;
	for (int k = 2;; k++)
	{
		int currJacob = JacobsthalNumber(k);
		int jacobDiff = currJacob - prevJacob;
		int offset = 0;
		if (jacobDiff > static_cast<int>(pend.size()))
			break;
		int insertTime = jacobDiff;
		std::deque<Iterator>::iterator pendIt = Advance(pend.begin(), jacobDiff - 1);
		std::deque<Iterator>::iterator upperLimitIt =
			Advance(main.begin(), currJacob + insertedCount);
		while (insertTime)
		{
			std::deque<Iterator>::iterator insertIt =
				std::upper_bound(main.begin(), upperLimitIt, *pendIt, Compare<Iterator>);
			std::deque<Iterator>::iterator inserted = main.insert(insertIt, *pendIt);
			insertTime--;
			pendIt = pend.erase(pendIt);
			std::advance(pendIt, -1);
			offset += std::distance(main.begin(), inserted) == currJacob + insertedCount;
			upperLimitIt = Advance(main.begin(), currJacob + insertedCount - offset);
		}
		prevJacob = currJacob;
		insertedCount += jacobDiff;
		offset = 0;
	}
	for (int i = static_cast<int>(pend.size()) - 1; i >= 0; i--)
	{
		std::deque<Iterator>::iterator currPend = Advance(pend.begin(), i);
		std::deque<Iterator>::iterator currBound =
			Advance(main.begin(), main.size() - pend.size() + i + isOdd);
		std::deque<Iterator>::iterator insertIt =
			std::upper_bound(main.begin(), currBound, *currPend, Compare<Iterator>);
		main.insert(insertIt, *currPend);
	}

	std::deque<int> copy;
	for (std::deque<Iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		for (size_t i = 0; i < tupleSize; i++)
		{
			Iterator tupleStart = *it;
			std::advance(tupleStart, -tupleSize + i + 1);
			copy.insert(copy.end(), *tupleStart);
		}
	}

	Iterator xIt = X.begin();
	std::deque<int>::iterator copyIt = copy.begin();
	while (copyIt != copy.end())
	{
		*xIt = *copyIt;
		xIt++;
		copyIt++;
	}
}
