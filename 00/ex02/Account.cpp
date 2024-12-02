#include "./Account.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int Account::nbAccounts = 0;
int Account::totalAmount = 0;
int Account::totalNbDeposits = 0;
int Account::totalNbWithdrawals = 0;

Account::Account(void)
{
	accountIndex_ = 0;
	amount_ = 0;
	nbDeposits_ = 0;
	nbWithdrawals_ = 0;
}

Account::Account(int initialDeposit)
{
	accountIndex_ = nbAccounts;
	amount_ = initialDeposit;
	nbWithdrawals_ = 0;
	nbDeposits_ = 0;
	totalAmount += initialDeposit;
	nbAccounts++;
	displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << accountIndex_ << ";";
	std::cout << "amount:" << amount_ << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << accountIndex_ << ";";
	std::cout << "amount:" << amount_ << ";";
	std::cout << "closed" << std::endl;
}

void Account::displayTimestamp(void)
{
	std::time_t now = std::time(0); // 現在時刻を取得
	std::tm* nowTm = std::localtime(&now); // 現在時刻をローカル時刻に変換
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", nowTm); // 時刻をフォーマット
	std::stringstream ss;
	ss << buffer;
	std::cout << "[";
	std::cout << ss.str();
	std::cout << "]";
}

void Account::makeDeposit(int deposit)
{
	displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << accountIndex_ << ";";
	std::cout << "p_amount:" << amount_ << ";";
	std::cout << "deposit:" << deposit << ";";
	amount_ += deposit;
	std::cout << "amount:" << amount_ << ";";
	nbDeposits_++;
	std::cout << "nb_deposits:" << nbDeposits_;
	std::cout << std::endl;
	totalAmount += deposit;
	totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << accountIndex_ << ";";
	std::cout << "p_amount:" << amount_ << ";";
	std::cout << "withdrawal:";
	if (amount_ < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	amount_ -= withdrawal;
	std::cout << "amount:" << amount_ << ";";
	nbWithdrawals_++;
	std::cout << "nb_withdrawals:" << nbWithdrawals_;
	std::cout << std::endl;
	totalAmount -= withdrawal;
	totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount(void) const
{
	return (amount_);
}

void Account::displayStatus(void) const
{
	displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << accountIndex_ << ";";
	std::cout << "amount:" << amount_ << ";";
	std::cout << "deposits:" << nbDeposits_ << ";";
	std::cout << "withdrawals:" << nbWithdrawals_;
	std::cout << std::endl;
}

int Account::getNbAccounts(void)
{
	return (nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (totalAmount);
}

int Account::getNbDeposits(void)
{
	return (totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	displayTimestamp();
	std::cout << " ";
	std::cout << "accounts:" << nbAccounts << ";";
	std::cout << "total:" << totalAmount << ";";
	std::cout << "deposits:" << totalNbDeposits << ";";
	std::cout << "withdrawals:" << totalNbWithdrawals;
	std::cout << std::endl;
}