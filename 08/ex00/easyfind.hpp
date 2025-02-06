#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &t, int i)
{
	typename T::iterator	it = std::find(t.begin(), t.end(), i);

	if (it == t.end())
		throw std::out_of_range("could't find");
	return it;
}

#endif
