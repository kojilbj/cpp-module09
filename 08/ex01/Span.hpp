#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span& src);

	Span& operator=(const Span& other);

	~Span();

	void addNumber(int N);
	void addRandomNumber();

	int shortestSpan();
	int longestSpan();

	void printElements();

private:
	Span();
	std::vector<int> numbers_;
};

#endif
