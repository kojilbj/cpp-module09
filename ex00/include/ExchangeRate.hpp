#ifndef EXCHANGERATE_HPP
#define EXCHANGERATE_HPP

#include <time.h>
#include <string>

struct ExchangeRate
{
public:
	ExchangeRate(const std::string& date, float rate);
	ExchangeRate(time_t date, float rate);

	ExchangeRate(const ExchangeRate& src);
	ExchangeRate& operator=(const ExchangeRate& other);

	~ExchangeRate();

	time_t getDate() const;
	float getRate() const;

	static time_t convertToTime(const std::string& date);

private:
	float rate_;
	time_t date_;

	ExchangeRate();
};

std::ostream& operator<<(std::ostream& out, const ExchangeRate& ex);

#endif
