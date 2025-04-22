#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <list>

#include "ExchangeRate.hpp"
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);

	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void readRateFile(const std::string& fileName);
	void readExchangeFile(const std::string& fileName);

	float calculate(const std::string& date, const std::string& price) const;
	float findRate(const std::string& date) const;

private:
	std::vector<struct ExchangeRate> rateHistory_;

	void parseLine(const std::string& line, std::string& date, std::string& price) const;
	float toFloat(const std::string& str) const;
};

#endif
