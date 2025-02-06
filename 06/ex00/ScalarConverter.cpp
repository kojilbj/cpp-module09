#include <iostream>
#include <sstream>

#include "ScalarConverter.hpp"

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

#define CHAR 1
#define INT 2
#define DOUBLE 3
#define FLOAT 4

int	ScalarConverter::detectType(const std::string &str)
{
	if (str == "+inf" || str == "-inf" || str == "nan")
		return DOUBLE;
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return FLOAT;
	if (str.size() == 1 && !std::isdigit(str[0]))
		return CHAR;
	else if (!std::isdigit(str[0]))
		return 0;
	else if (str.find('f') == std::string::npos && str.find('.') == std::string::npos)
		return INT;
	else if (str.find('f') != std::string::npos)
		return FLOAT;
	else if (str.find('.') != std::string::npos)
		return DOUBLE;
	return 0;
}

void	ScalarConverter::ConvertViaChar(const std::string &str)
{
	char	c = 0;
	int	i = 0;
	float	f = 0;
	double	d = 0;

	std::stringstream ss;

	ss << str;
	ss >> c;

	PrintChar(c);
	std::cout << std::endl;
	
	i = static_cast<int>(c);
	PrintInt(i);
	std::cout << std::endl;

	f = static_cast<float>(c);
	PrintFloat(f);
	std::cout << std::endl;

	d = static_cast<double>(c);
	PrintDouble(d);
	std::cout << std::endl;
}

void	ScalarConverter::ConvertViaInt(const std::string &str)
{
	char	c = 0;
	int	i = 0;
	float	f = 0;
	double	d = 0;
	std::stringstream ss;

	ss << str;
	ss >> i;

	c = static_cast<char>(i);
	PrintChar(c);
	std::cout << std::endl;

	PrintInt(i);
	std::cout << std::endl;

	f = static_cast<float>(i);
	PrintFloat(f);
	std::cout << std::endl;

	d = static_cast<double>(i);
	PrintDouble(d);
	std::cout << std::endl;
}
void	ScalarConverter::ConvertViaFloat(const std::string &str)
{
	char	c = 0;
	int	i = 0;
	float	f = 0;
	double	d = 0;
	std::stringstream ss(str);

	ss << str;
	ss >> f;

	c = static_cast<char>(f);
	PrintChar(c);
	std::cout << std::endl;

	i = static_cast<int>(f);
	PrintInt(i);
	std::cout << std::endl;

	PrintFloat(f);
	std::cout << std::endl;

	d = static_cast<double>(f);
	PrintDouble(d);
	std::cout << std::endl;
}
void	ScalarConverter::ConvertViaDouble(const std::string &str)
{
	char	c = 0;
	int	i = 0;
	float	f = 0;
	double	d = 0;
	std::stringstream ss(str);

	ss << str;
	ss >> d;

	c = static_cast<char>(d);
	PrintChar(c);
	std::cout << std::endl;

	i = static_cast<int>(d);
	PrintInt(i);
	std::cout << std::endl;

	f = static_cast<double>(d);
	PrintFloat(f);
	std::cout << std::endl;

	PrintDouble(d);
	std::cout << std::endl;
}

void	ScalarConverter::PrintChar(char c, bool isError)
{
	std::cout << "char: ";
	if (isError)
	{
		std::cout << "impossible";
		return ;
	}
	if (!std::isprint(c))
	{
		std::cout << "undisplable";
		return ;
	}
	else
		std::cout << "'" << c << "'";
}

void	ScalarConverter::PrintInt(int i, bool isError)
{
	std::cout << "int: ";
	if (isError)
	{
		std::cout << "impossible";
		return ;
	}
	std::cout << i;
}

void	ScalarConverter::PrintFloat(float f, bool isError)
{
	float	max = std::numeric_limits<float>::max();
	float	min = - std::numeric_limits<float>::max();

	std::cout << "float: ";
	if (isError)
	{
		std::cout << "impossible";
		return ;
	}
	else if (f == max)
	{
		std::cout << "+inff";
		return ;
	}
	else if (f == min)
	{
		std::cout << "-inff";
		return ;
	}
	std::cout << f << "f";
}

void	ScalarConverter::PrintDouble(double d, bool isError)
{
	float	max = std::numeric_limits<double>::max();
	float	min = - std::numeric_limits<double>::max();

	std::cout << "double: ";
	if (isError)
	{
		std::cout << "impossible";
		return ;
	}
	else if (d == max)
	{
		std::cout << "+inf";
		return ;
	}
	else if (d == min)
	{
		std::cout << "-inf";
		return ;
	}
	std::cout << d;
}

void	ScalarConverter::convert(const std::string &str)
{
	int	type;

	type = detectType(str);
	switch (type)
	{
		case (CHAR):
			ConvertViaChar(str);
			break ;
		case (INT):
			ConvertViaInt(str);
			break ;
		case (FLOAT):
			ConvertViaFloat(str);
			break ;
		case (DOUBLE):
			ConvertViaDouble(str);
			break ;
		default:
			std::cout << "default" << std::endl;
	}
}
