#include <iostream>
#include <sstream>
#include <string>

#include "ExchangeRate.hpp"

ExchangeRate::ExchangeRate(const std::string& date, float rate)
	: rate_(rate)
{
	this->date_ = convertToTime(date);
}

ExchangeRate::ExchangeRate(time_t date, float rate)
	: rate_(rate), date_(date)
{ }

ExchangeRate::ExchangeRate()
	: rate_(0), date_(0)
{ }

ExchangeRate::ExchangeRate(const ExchangeRate& src)
	: rate_(src.rate_), date_(src.date_)
{ }

ExchangeRate& ExchangeRate::operator=(const ExchangeRate& other)
{
	if (this == &other)
		return *this;
	this->rate_ = other.rate_;
	this->date_ = other.date_;
	return *this;
}

ExchangeRate::~ExchangeRate() { }

time_t ExchangeRate::convertToTime(const std::string& date)
{
	char deli = '-';
	std::stringstream ss(date);
	tm tm = {};

	ss >> tm.tm_year >> deli >> tm.tm_mon >> deli >> tm.tm_mday;
	if (ss.fail())
	{
		throw std::logic_error("Error: bad input => " + date);
	}

	if (tm.tm_mon < 1 || tm.tm_mon > 12)
	{
		throw std::logic_error("Error: bad input => " + date);
	}

	if (tm.tm_mday < 1 || tm.tm_mday > 31)
	{
		throw std::logic_error("Error: bad input => " + date);
	}

	tm.tm_year -= 1900;
	tm.tm_mon -= 1;

	time_t time = mktime(&tm);
	if (time == -1)
	{
		throw std::logic_error("Error: mktime failed for date => " + date);
	}
	return time;
}

time_t ExchangeRate::getDate() const
{
	return this->date_;
}

float ExchangeRate::getRate() const
{
	return this->rate_;
}

std::ostream& operator<<(std::ostream& out, const ExchangeRate& ex)
{
	out << "date: " << ex.getDate() << " rate: " << ex.getRate();
	return out;
}
