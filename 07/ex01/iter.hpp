#ifndef ITER_HPP
#define ITER_HPP

template <class T>
void	iter(T *arrayPtr, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; i++)
	{
		func(arrayPtr[i]);
	}
}

#endif
