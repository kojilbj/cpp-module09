#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <random>

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

bool	isNonZero(int i)
{
	return i != 0;
}

int	Span::shortestSpan()
{
	int	span = 0;
	std::vector<int>	diffs(numbers_.size());
	std::vector<int>::const_iterator	it;

	if (numbers_.size() == 0)
		throw std::out_of_range("container is empty.");
	if (numbers_.size() == 1)
		throw std::logic_error("container has only one element");
	std::sort(numbers_.begin(), numbers_.end());
	std::adjacent_difference(numbers_.begin(), numbers_.end(), diffs.begin());
	it = std::find_if(diffs.begin() + 1, diffs.end(), isNonZero);
	if (it == diffs.end())
		throw std::logic_error("no span");
	span = *std::min_element(diffs.begin(), diffs.end());
	return span;
}

int	Span::longestSpan()
{
	int	span;

	if (numbers_.size() == 0)
		throw std::out_of_range("container is empty.");
	if (numbers_.size() == 1)
		throw std::logic_error("container has only one element");
	std::sort(numbers_.begin(), numbers_.end());
	span = *(numbers_.end() - 1) - *numbers_.begin();
	if (span == 0)
		throw std::logic_error("no span");
	return span;
}

void	Span::addRandomNumber()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 10000);

	while (1)
	{
		try
		{
			addNumber(dist(gen));
		}
		catch (const std::exception &e)
		{
			//std::cout << e.what() << std::endl;
			return;
		}
	}
}

void	Span::printElements()
{
	for (std::vector<int>::iterator it = numbers_.begin(); it != numbers_.end(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}
