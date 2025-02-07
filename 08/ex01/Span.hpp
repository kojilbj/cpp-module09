#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &src);

	Span	&operator=(const Span &other);

	~Span();

	void	addNumber(int n);

	int	shortestSpan();
	int	longestSpan();

private:
	std::vector<int> numbers_;
};

#endif
