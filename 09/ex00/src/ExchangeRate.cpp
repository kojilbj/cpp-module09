#include <sstream>

#include "ExchangeRate.hpp"

ExchangeRate::ExchangeRate(const std::string &date, const Fixed &rate): rate_(rate), dateString_(date)
{
	try
	{
		this->date_ = ConvertToTime(dateString_);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		throw std::exception();
	}
}

ExchangeRate::ExchangeRate(time_t date, const Fixed &rate): rate_(rate), date_(date)
{
}

ExchangeRate::~ExchangeRate()
{
}

time_t	ExchangeRate::ConvertToTime(const std::string &date)
{
	char	deli = '-';
	std::stringstream	ss(date);
	std::tm	tm = {};

	ss >> tm.tm_year >> deli >> tm.tm_mon >> deli >> tm.tm_mday;
	tm.tm_year = tm.tm_year - 1900;
	tm.tm_mon = tm.tm_mon - 1;
	return std::mktime(&tm);
}

std::string	ExchangeRate::getDateString() const
{
	return this->dateString_;
}

time_t	ExchangeRate::getDate() const
{
	return this->date_;
}

Fixed	ExchangeRate::getRate() const
{
	return this->rate_;
}

std::ostream	&operator<<(std::ostream &out, const ExchangeRate &ex)
{
	out << "date: " << ex.getDate() << " rate: " << ex.getRate();
	return out;
}
