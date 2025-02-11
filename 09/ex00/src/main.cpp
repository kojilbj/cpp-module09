#include <string>
#include <iostream>

#include "BitcoinExchange.hpp"
#include "Fixed.hpp"
#include "ExchangeRate.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}
	BitcoinExchange	btc;
	btc.ReadRateFile("data.csv");
	btc.ReadExchangeFile(std::string(av[1]));
	return 0;
}
