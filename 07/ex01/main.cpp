#include <iostream>
#include <string>

#include "iter.hpp"

template <class T>
void	iter(T *arrayPtr, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; i++)
	{
		func(arrayPtr[i]);
	}
}

template <class T>
void	print(T a)
{
	std::cout << a;
}

int	main(void)
{
	std::string	strs[] = {"Hello", "World", "!"};

	::iter(strs, sizeof(strs) / sizeof(strs[0]), &print);
}
