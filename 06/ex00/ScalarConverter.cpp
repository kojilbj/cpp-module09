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

	std::cout << "char: '" << c << "'" << std::endl;

	i = static_cast<int>(c);
	std::cout << "int: " << i << std::endl;

	f = static_cast<float>(c);
	std::cout << "float: " << f << "f" << std::endl;

	d = static_cast<double>(c);
	std::cout << "double: " << d << std::endl;
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
	std::cout << "char: '" << c << "'" << std::endl;

	std::cout << "int: " << i << std::endl;

	f = static_cast<float>(i);
	std::cout << "float: " << f << "f" << std::endl;

	d = static_cast<double>(i);
	std::cout << "double: " << d << std::endl;
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
	std::cout << "char: '" << c << "'" << std::endl;

	i = static_cast<int>(f);
	std::cout << "int: " << i << std::endl;

	std::cout << "float: " << f << "f" << std::endl;

	d = static_cast<double>(f);
	std::cout << "double: " << d << std::endl;
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
	std::cout << "char: '" << c << "'" << std::endl;

	i = static_cast<int>(d);
	std::cout << "int: " << i << std::endl;

	f = static_cast<double>(d);
	std::cout << "float: " << f << "f" << std::endl;

	std::cout << "double: " << d << std::endl;
}
void	ScalarConverter::convert(const std::string &str)
{
	int	type;

	type = detectType(str);
	switch (type)
	{
		case (CHAR):
			std::cout << "char" << std::endl;
			ConvertViaChar(str);
			break ;
		case (INT):
			std::cout << "int" << std::endl;
			ConvertViaInt(str);
			break ;
		case (FLOAT):
			std::cout << "float" << std::endl;
			ConvertViaFloat(str);
			break ;
		case (DOUBLE):
			std::cout << "double" << std::endl;
			ConvertViaDouble(str);
			break ;
		default:
			std::cout << "default" << std::endl;
	}
}
