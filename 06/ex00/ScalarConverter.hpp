#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class	ScalarConverter
{
public:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter(void);
	ScalarConverter	&operator=(const ScalarConverter &other);

	static void	convert(const std::string &in);
private:
	static void	ConvertToChar(const std::string &in);
	static void	ConvertToInt(const std::string &in);
	static void	ConvertToFloat(const std::string &in);
	static void	ConvertToDouble(const std::string &in);

};
#endif
