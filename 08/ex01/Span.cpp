#include <algorithm>
#include <iostream>
#include <numeric>
#include <ctime>
#include <string>
#include <string>
#include <unistd.h>

#include "Span.hpp"

Span::Span()
{
	numbers_.reserve(10);
}

Span::Span(unsigned int n)
{
	numbers_.reserve(n);
}

Span::Span(const Span& src)
{
	this->numbers_ = src.numbers_;
}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return *this;
	std::vector<int>::const_iterator otherIt = other.numbers_.begin();
	this->numbers_.clear();
	for (size_t i = 0; i < this->numbers_.capacity(); i++)
	{
		if (otherIt == other.numbers_.end())
			break;
		this->numbers_.push_back(*otherIt);
		otherIt++;
	}
	return *this;
}

Span::~Span() { }

void Span::addNumber(int n)
{
	if (numbers_.capacity() == numbers_.size())
		throw std::out_of_range("over");
	numbers_.push_back(n);
}

bool isNonZero(int i)
{
	return i != 0;
}

int Span::shortestSpan()
{
	int span = 0;
	std::vector<int> diffs(numbers_.size());
	std::vector<int>::const_iterator it;

	if (numbers_.size() == 0)
		throw std::out_of_range("container is empty.");
	if (numbers_.size() == 1)
		throw std::logic_error("container has only one element");
	std::sort(numbers_.begin(), numbers_.end());
	std::adjacent_difference(numbers_.begin(), numbers_.end(), diffs.begin());
	std::sort(diffs.begin() + 1, diffs.end());
	it = std::find_if(diffs.begin() + 1, diffs.end(), isNonZero);
	if (it == diffs.end())
		throw std::logic_error("no span");
	span = *it;
	return span;
}

int Span::longestSpan()
{
	int span;

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

void Span::addRandomNumber()
{
	std::srand(std::time(0));
	while (1)
	{
		try
		{
			addNumber(std::rand() % 10000001);
		}
		catch (const std::exception& e)
		{
			//std::cout << e.what() << std::endl;
			return;
		}
	}
}

void Span::printElements()
{
	for (std::vector<int>::iterator it = numbers_.begin(); it != numbers_.end(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}
