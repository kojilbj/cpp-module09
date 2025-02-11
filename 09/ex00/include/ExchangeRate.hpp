#ifndef EXCHANGERATE_HPP
#define EXCHANGERATE_HPP

#include <time.h>

#include "Fixed.hpp"

class	ExchangeRate
{
public:
	ExchangeRate(const std::string &date, const Fixed &rate);
	ExchangeRate(time_t date, const Fixed &rate);

	~ExchangeRate();

	std::string getDateString() const;
	time_t	getDate() const;
	Fixed getRate() const;

	static time_t	ConvertToTime(const std::string &date);

private:
	Fixed	rate_;
	time_t	date_;
	std::string	dateString_;

	ExchangeRate();
};

std::ostream	&operator<<(std::ostream &out, const ExchangeRate&ex);

#endif
