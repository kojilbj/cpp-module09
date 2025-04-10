#include <exception>
#include <iostream>
#include <sstream>

namespace RPN
{
	int toInt(const std::string& str)
	{
		std::stringstream ss(str);
		int result;
		ss >> result;

		if (ss.fail())
		{
			throw std::runtime_error("Error");
		}

		return result;
	}

	void getValues(std::stack<int>& stack, int& left, int& right)
	{
		if (stack.size() < 2)
			throw std::runtime_error("Error");
		right = stack.top();
		stack.pop();
		left = stack.top();
		stack.pop();
	}

	int calculate(std::stringstream fomula)
	{
		std::stack<int> stack;
		std::string buff;

		while (std::getline(fomula, buff, ' '))
		{
			int right, left;
			if (buff == "+")
			{
				getValues(stack, left, right);
				stack.push(left + right);
			}
			else if (buff == "-")
			{
				getValues(stack, left, right);
				stack.push(left - right);
			}
			else if (buff == "*")
			{
				getValues(stack, left, right);
				stack.push(left * right);
			}
			else if (buff == "/")
			{
				getValues(stack, left, right);
				stack.push(left / right);
			}
			else
			{
				stack.push(toInt(buff));
			}
		}
		if (stack.size() != 1)
			throw std::runtime_error("Error");
		return stack.top();
	}

} // namespace RPN