#include "ScalarConverter.hpp"

int	main(int ac, char *argv[])
{
	if (ac != 2)
		return 0;
	ScalarConverter::convert(std::string(argv[1]));
	return 0;
}
