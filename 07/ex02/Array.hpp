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

	Array(unsigned int n) : size_(n)
	{
		this->arrayPtr_ = new T[size_];
	}

	Array(const Array &src)
	{
		this->size_ = src.size();
		this->arrayPtr_ = new T[size_];
		for (size_t i = 0; i < size_; i++)
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
		delete[] this->arrayPtr_;
		this->size_ = other.size();
		this->arrayPtr_ = new T[size_];
		for (size_t i = 0; i < size_; i++)
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
