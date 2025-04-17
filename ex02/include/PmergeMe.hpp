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
private:
	static void	FordJohnsonSort(std::deque<int> &list);
	static void	FordJohnsonSort(std::list<int> &deque);
};

#endif
