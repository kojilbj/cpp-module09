#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

template <typename T>
typename T::iterator	easyfind(T &t, int i)
{
	for (typename T::iterator it = t.begin(); it != t.end(); it++)
	{
		if (*it == i)
			return it;
	}
	throw std::exception();
}

#endif
