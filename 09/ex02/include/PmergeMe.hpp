#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <deque>

class	PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &);

	PmergeMe	&operator=(const PmergeMe &);
	~PmergeMe();

	std::list<int>	ListProcess();
	std::deque<int>	DequeProcess();
private:
};

#endif
