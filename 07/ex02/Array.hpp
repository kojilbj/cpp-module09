#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class	Array
{
public:
	Array(void) : arrayPtr_(NULL), size_(0)
	{
	}

	Array(unsigned int n) : arrayPtr_(new T[n]()), size_(n)
	{
	}

	Array(const Array &src)
	{
		this->arrayPtr_ = new T[src.size()]();
		for (size_t i = 0; i < src.size(); i++)
		{
			this->arrayPtr_[i] = src.arrayPtr_[i];
		}
	}

	~Array(void)
	{
		delete[] arrayPtr_;
	}

	Array	&operator=(const Array &other)
	{
		if (this == &other)
			return *this;
		this->arrayPtr_ = new T[other.size()];
		this->size_ = other.size();
		for (size_t i = 0; i < other.size(); i++)
		{
			this->arrayPtr_[i] = other.arrayPtr_[i];
		}
		return *this;
	}

	T	&operator[](size_t index)
	{
		if (index >= this->size())
		{
			throw std::exception();
		}
		return this->arrayPtr_[index];
	}

	size_t	size(void) const
	{
		return size_;
	}

private:
	T	*arrayPtr_;
	size_t	size_;
};

#endif
