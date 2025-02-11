#include <iostream>
#include <sstream>
#include <fstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	//this->ReadRateFile("data.csv");
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::ReadRateFile(const std::string &fileName)
{
	std::ifstream	file(fileName);
	std::string	buff;

	if (!file.is_open())
	{
		std::cout << "Error: could not open " << fileName << std::endl;
		return ;
	}
	std::getline(file, buff);
	while (std::getline(file, buff))
	{
		std::stringstream	ss(buff);
		std::string	date;
		std::string	price;

		std::getline(ss, date, ',');
		std::getline(ss, price);
		ExchangeRate	ex(date, std::stof(price));

		rateHistory_.push_back(ex);
	}
}

void	BitcoinExchange::ReadExchangeFile(const std::string &fileName)
{
	std::ifstream	file(fileName);
	std::string	buff;

	if (!file.is_open())
	{
		std::cout << "Error: could not open " << fileName << std::endl;
		return ;
	}
	std::getline(file, buff);
	while (std::getline(file, buff))
	{
		std::stringstream	ss(buff);
		std::string	date;
		std::string	price;

		std::getline(ss, date, '|');
		std::getline(ss, price);

		try
		{
			Fixed	ex = Calculate(date, price);
			std::cout << date << " => " << price << " = " << ex << std::endl;
		}
		catch (const std::string &e)
		{
			std::cout << e << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: bad input => "<< date << std::endl;
		}
	}
}

Fixed	BitcoinExchange::Calculate(const std::string &date, const std::string &price) const
{
	Fixed	rate;
	Fixed	tmp;
	Fixed	fixedPrice(std::stof(price));

	if (fixedPrice < 0)
		throw std::string("Error: not a positve number.");
	rate = findRate(date);
	tmp = rate * fixedPrice;
	if (tmp < 0)
		throw std::string("Error: too large a number.");
	return tmp;
}

Fixed	BitcoinExchange::findRate(const std::string &date) const
{
	time_t	dt = ExchangeRate::ConvertToTime(date);
	Fixed	rate;
	std::vector<ExchangeRate>::const_iterator tmpIt = rateHistory_.end();

	for (std::vector<ExchangeRate>::const_iterator it = rateHistory_.begin(); it != rateHistory_.end(); it++)
	{
		if (it->getDate() == dt)
		{
			rate = it->getRate();
			break ;
		}
		if (tmpIt != rateHistory_.end() && tmpIt->getDate() < dt && dt < it->getDate())
		{
			rate = tmpIt->getRate();
			break ;
		}
		tmpIt = it;
	}
	return rate;
}
