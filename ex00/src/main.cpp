#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"
#include "ExchangeRate.hpp"

int main(int ac, char* av[])
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}
	BitcoinExchange btc;
	try
	{
		btc.readRateFile("data.csv");
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	try
	{
		btc.readExchangeFile(std::string(av[1]));
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
