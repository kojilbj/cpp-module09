#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include "Fixed.hpp"
#include "ExchangeRate.hpp"

class	BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();

	void	ReadRateFile(const std::string &fileName);
	void	ReadExchangeFile(const std::string &fileName);

	Fixed	Calculate(const std::string &date, const std::string &price) const;
	Fixed	findRate(const std::string &date) const;

private:
	std::vector<ExchangeRate>	rateHistory_;
};

#endif

