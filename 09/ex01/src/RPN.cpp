#include <exception>
#include <iostream>
#include <sstream>

namespace RPN
{
	enum Operator
	{
		NONE,
		ADD,
		SUB,
		MUL,
		DIV
	};

	int toInt(const std::string& str)
	{
		std::stringstream ss(str);
		int result;
		ss >> result;

		if (ss.fail())
		{
			throw std::runtime_error("Error toInt: " + str);
		}

		return result;
	}

	void getValues(std::stack<int>& stack, int& left, int& right)
	{
		if (stack.size() < 2)
			throw std::runtime_error("Error getValues");
		right = stack.top();
		stack.pop();
		left = stack.top();
		stack.pop();
	}

	Operator getOperator(const std::string& op)
	{
		if (op == "+")
			return ADD;
		if (op == "-")
			return SUB;
		if (op == "/")
			return DIV;
		if (op == "*")
			return MUL;
		return NONE;
	}

	int calculate(std::stringstream fomula)
	{
		std::stack<int> stack;
		std::string buff;

		while (std::getline(fomula, buff, ' '))
		{
			std::cout << buff << std::endl;
			int right, left;
			Operator op = getOperator(buff);
			if (op != NONE)
			{
				getValues(stack, left, right);
				switch (op)
				{
				case ADD:
					stack.push(left + right);
					break;
				case SUB:
					stack.push(left - right);
					break;
				case MUL:
					stack.push(left * right);
					break;
				case DIV:
					stack.push(left / right);
					break;
				default:
					break;
				}
			}
			else
			{
				stack.push(toInt(buff));
			}
		}
		if (stack.size() != 1)
			throw std::runtime_error("Error calcurate");
		return stack.top();
	}

} // namespace RPN