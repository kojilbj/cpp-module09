#include <iostream>
#include <string>

#include "iter.hpp"

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
