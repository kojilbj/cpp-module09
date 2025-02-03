#include "ScalarConverter.hpp"

#include <iostream>

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter Default Constructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	std::cout << "ScalarConverter Copy Constructor Called" << std::endl;
	static_cast<void>(src);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter Destructor Called" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	static_cast<void>(other);
	return *this;
}

void	ScalarConverter::ConvertToChar(const std::string &in)
{
	int	c;
	int	max;
	int	min;

	max = std::numeric_limits<char>::max();
	min = std::numeric_limits<char>::min();
	std::cout << "char: " ;
	try
	{
		c = std::stoi(in);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "nan";
		return ;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "impossible";
		return ;
	}
	if (max == c)
		std::cout << "+inf";
	else if (min == c)
		std::cout << "-inf";
	else if (c > max || c < min)
		std::cout << "impossible";
	else if (std::isprint(c))
		std::cout << c;
	else
		std::cout << "Non displayable";
	return ;
}

void	ScalarConverter::ConvertToInt(const std::string &in)
{
	int	i;
	int	max;
	int	min;

	max = std::numeric_limits<int>::max();
	min = std::numeric_limits<int>::min();
	std::cout << "int: " ;
	try
	{
		i = std::stoi(in);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "nan";
		return ;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "impossible";
		return ;
	}
	if (max == i)
		std::cout << "+inf";
	else if (min == i)
		std::cout << "-inf";
	else if (i > max || i < min)
		std::cout << "impossible";
	else
		std::cout << i;
	return ;
}

void	ScalarConverter::ConvertToFloat(const std::string &in)
{
	float	f;
	float	max;
	float	min;

	max = std::numeric_limits<float>::max();
	min = std::numeric_limits<float>::lowest();
	std::cout << "float: " ;
	try
	{
		f = std::stof(in);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "nanf";
		return ;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "impossible";
		return ;
	}
	if (max == f)
		std::cout << "+inff";
	else if (min == f)
		std::cout << "-inff";
	else if (f > max || f < min)
		std::cout << "impossible";
	else
		std::cout << f << "f";
	return ;
}

void	ScalarConverter::ConvertToDouble(const std::string &in)
{
	double	d;
	double	max;
	double	min;

	max = std::numeric_limits<double>::max();
	min = std::numeric_limits<double>::lowest();
	std::cout << "double: " ;
	try
	{
		d = std::stod(in);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "nan";
		return ;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "impossible";
		return ;
	}
	if (max == d)
		std::cout << "+inf";
	else if (min == d)
		std::cout << "-inf";
	else if (d > max || d < min)
		std::cout << "impossible";
	else
		std::cout << d;
	return ;
}

void	ScalarConverter::convert(const std::string &in)
{
	ConvertToChar(in);
	std::cout << std::endl;

	ConvertToInt(in);
	std::cout << std::endl;

	ConvertToFloat(in);
	std::cout << std::endl;

	ConvertToDouble(in);
	std::cout << std::endl;
}
