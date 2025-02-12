#include <iostream>
#include <sstream>

#include "RPN.hpp"

std::stack<int>	RPN::stack_;

RPN::RPN()
{
	while (!stack_.empty())
	{
		stack_.pop();
	}
}

RPN::~RPN()
{
	std::cout << "RPN Destrucor Called" << std::endl;
}

int	RPN::Calculate(const std::string &formula)
{
	Parse(formula);
	return stack_.top();
}

void	RPN::Parse(const std::string &formula)
{
	std::stringstream	ss(formula);
	std::string	buff;

	while (std::getline(ss, buff, ' '))
	{
		if (buff == "+")
		{
			int	a = stack_.top();
			stack_.pop();
			int	b = stack_.top();
			stack_.pop();
			stack_.push(b + a);
		}
		else if (buff == "-")
		{
			int	a = stack_.top();
			stack_.pop();
			int	b = stack_.top();
			stack_.pop();
			stack_.push(b - a);
		}
		else if (buff == "*")
		{
			int	a = stack_.top();
			stack_.pop();
			int	b = stack_.top();
			stack_.pop();
			stack_.push(b * a);
		}
		else if (buff == "/")
		{
			int	a = stack_.top();
			stack_.pop();
			int	b = stack_.top();
			stack_.pop();
			stack_.push(b / a);
		}
		else
		{
			try
			{
				stack_.push(std::stoi(buff));
			}
			catch (const std::exception &e)
			{
				throw e;
			}
		}
	}
	if (stack_.size() != 1)
		throw std::exception();
}
