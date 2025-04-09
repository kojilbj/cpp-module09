#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	MutantStack()
		: std::stack<T, Container>()
	{ }

	MutantStack(const MutantStack& src)
		: std::stack<T, Container>(src)
	{ }

	MutantStack& operator=(const MutantStack& other)
	{
		if (this == &other)
			return *this;
		this->c = other.c;
		return *this;
	}

	~MutantStack() { }

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

	const_iterator begin() const
	{
		return this->c.begin();
	}

	const_iterator end() const
	{
		return this->c.end();
	}

private:
};

#endif
