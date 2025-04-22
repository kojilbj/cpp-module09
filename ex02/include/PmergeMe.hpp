#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <deque>
#include <iterator>
#include <algorithm>


class	PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &);

	PmergeMe	&operator=(const PmergeMe &);
	virtual ~PmergeMe() = 0;

	static std::list<int>	ListProcess(char *av[]);
	static std::deque<int>	DequeProcess(char *av[]);

	template <typename T>
	static void	print(const T &container)
	{
		for (typename T::const_iterator it = container.begin(); it != container.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	static int toInt(const std::string& str);

	static int compareCount;
private:
	static void	FordJohnsonSort(std::list<int>& X, size_t tupleSize);
	static void	FordJohnsonSort(std::deque<int> &deque, size_t tupleSize);
	
	static size_t	JacobsthalNumber(size_t n);



};

template <typename T>
bool	Compare(T left, T right)
{
	PmergeMe::compareCount++;
	return *left < *right;
}

template <typename T>
T Advance(T it, int distance)
{
	std::advance(it, distance);
	return it;
}

template <typename T>
void	SwapPair(T it, size_t tupleSize)
{
	T start = Advance(it, -tupleSize + 1);
	T end = Advance(start, tupleSize);
	while (start != end)
	{
		std::iter_swap(start, Advance(start, tupleSize));
		start++;
	}
}

#endif
