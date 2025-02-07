#include <iostream>
#include <string>

#include "Span.hpp"

Span::Span(unsigned int N)
{
	numbers_.reserve(N);
}

Span::Span(const Span &src)
{
	this->numbers_ = src.numbers_;
}

Span	&Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	this->numbers_ = other.numbers_;
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int n)
{
	if (numbers_.capacity() == numbers_.size())
		throw std::out_of_range("over");
	numbers_.push_back(n);
}

int	Span::shortestSpan()
{
	return 0;
}

int	Span::longestSpan()
{
	return 0;
}
