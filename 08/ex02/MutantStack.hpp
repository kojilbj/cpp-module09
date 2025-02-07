#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack()
	{
	}

	MutantStack(const MutantStack &src)
	{
	}

	~MutantStack(){}

	typename MutantStack<T>::iterator	begin()
	{
		return this->c.begin();
	}

	typename MutantStack<T>::iterator	end()
	{
		return this->c.end();
	}


private:

};

#endif

