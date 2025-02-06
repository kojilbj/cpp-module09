#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class	ScalarConverter
{
public:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &src);
	virtual ~ScalarConverter(void) = 0;
	ScalarConverter	&operator=(const ScalarConverter &other);

	static void	convert(const std::string &in);
private:
	static int	detectType(const std::string &str);

	static void	ConvertViaChar(const std::string &str);
	static void	ConvertViaInt(const std::string &str);
	static void	ConvertViaFloat(const std::string &str);
	static void	ConvertViaDouble(const std::string &str);

};
#endif
