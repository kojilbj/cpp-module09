#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::deque<T>::iterator	iterator;

	MutantStack()
	{
	}

	MutantStack(const MutantStack &src) : std::stack<T>(src)
	{
	}

	MutantStack	&operator=(const MutantStack& other)
	{
		if (this == &other)
			return *this;
		this->c = other.c;
		return *this;
	}

	~MutantStack(){}

	typename std::deque<T>::iterator	begin()
	{
		return this->c.begin();
	}

	typename std::deque<T>::iterator	end()
	{
		return this->c.end();
	}


private:

};

#endif

