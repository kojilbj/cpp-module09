#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class	RPN
{
public:
	~RPN();

	static int	Calculate(const std::string &formula);
	static void	Parse(const std::string &formula);

private:
	RPN();
	static std::stack<int>	stack_;
};

#endif
