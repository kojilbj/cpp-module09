#include "MutantStack.hpp"
#include <deque>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	{
		std::cout << "MutantStack" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "\t" << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "\t" << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "\t" << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "std::vector" << std::endl;
		std::vector<int> mstack;
		mstack.push_back(5);
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << "\t" << *it << std::endl;
			++it;
		}
		std::stack<int, std::vector<int> > s(mstack);
	}

	{
		std::cout << "Copy Constructor Test" << std::endl;
		MutantStack<std::string> st1;
		st1.push("Hello");
		st1.push("World");
		MutantStack<std::string> st2(st1);
		for (MutantStack<std::string>::iterator it = st2.begin(); it != st2.end(); it++)
		{
			std::cout << "\t" << *it << std::endl;
		}
	}

	{
		std::cout << "Copy Operator Test" << std::endl;
		MutantStack<std::string> st1;
		st1.push("Hello");
		st1.push("World");
		MutantStack<std::string> st2;
		st2 = st1;
		for (MutantStack<std::string>::iterator it = st2.begin(); it != st2.end(); it++)
		{
			std::cout << "\t" << *it << std::endl;
		}
	}

	{
		std::cout << "Const Iteartor Test" << std::endl;
		MutantStack<std::string> st1;
		st1.push("Hello");
		st1.push("World");

		for (MutantStack<std::string>::const_iterator it = st1.begin(); it != st1.end(); it++)
		{
			std::cout << "\t" << *it << std::endl;
		}
	}
	return 0;
}
