#include "BitcoinExchange.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
	//this->ReadRateFile("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
	: rateHistory_(src.rateHistory_)
{ }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return *this;
	this->rateHistory_ = other.rateHistory_;
	return *this;
}

BitcoinExchange::~BitcoinExchange() { }

void BitcoinExchange::readRateFile(const std::string& fileName)
{
	std::ifstream file(fileName.c_str());
	std::string buff;

	if (!file.is_open())
	{
		throw std::logic_error("Error: could not open " + fileName);
	}
	std::getline(file, buff);
	while (std::getline(file, buff))
	{
		if (std::count(buff.begin(), buff.end(), ',') != 1)
		{
			throw std::logic_error("Error: bad input =>" + buff);
		}
		std::stringstream ss(buff);
		std::string date;
		std::string price;

		std::getline(ss, date, ',');
		std::getline(ss, price);
		struct ExchangeRate ex(date, toFloat(price));
		rateHistory_.push_back(ex);
	}
}

void BitcoinExchange::readExchangeFile(const std::string& fileName)
{
	std::ifstream file(fileName.c_str());
	std::string buff;

	if (!file.is_open())
	{
		throw std::logic_error("Error: could not open " + fileName);
	}
	std::getline(file, buff);
	while (std::getline(file, buff))
	{
		std::string date;
		std::string btc;
		try
		{
			parseLine(buff, date, btc);
			float price = calculate(date, btc);
			std::cout << date << " => " << btc << " = " << price << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::parseLine(const std::string& line, std::string& date, std::string& btc) const
{
	std::stringstream ss(line);

	if (std::count(line.begin(), line.end(), '|') != 1)
	{
		throw std::logic_error("Error: bad input => " + line);
	}
	std::getline(ss, date, '|');
	std::getline(ss, btc);
}

float BitcoinExchange::toFloat(const std::string& str) const
{
	std::stringstream ss(str);
	float result;
	ss >> result;

	if (ss.fail())
	{
		throw std::logic_error("Error: bad input =>" + str);
	}

	return result;
}

float BitcoinExchange::calculate(const std::string& date, const std::string& btc) const
{
	float rate;
	float price;
	float floatBtc(toFloat(btc));

	if (floatBtc < 0)
		throw std::logic_error("Error: not a positve number.");
	if (1000 < floatBtc)
		throw std::logic_error("Error: too large a number.");
	rate = findRate(date);
	price = rate * floatBtc;
	return price;
}

float BitcoinExchange::findRate(const std::string& date) const
{
	time_t dt = ExchangeRate::convertToTime(date);
	float rate = 0;
	std::vector<ExchangeRate>::const_iterator tmpIt = rateHistory_.end();

	if ((rateHistory_.end() - 1)->getDate() < dt)
	{
		return (rateHistory_.end() - 1)->getRate();
	}
	for (std::vector<ExchangeRate>::const_iterator it = rateHistory_.begin();
		 it != rateHistory_.end();
		 it++)
	{
		if (it->getDate() == dt)
		{
			rate = it->getRate();
			break;
		}
		if (tmpIt != rateHistory_.end() && tmpIt->getDate() < dt && dt < it->getDate())
		{
			rate = tmpIt->getRate();
			break;
		}
		tmpIt = it;
	}
	return rate;
}
