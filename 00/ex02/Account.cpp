#include <sys/time.h>
#include <ctime>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructor / Desctructor
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __

Account::Account(void):
	_accountIndex(Account::_nbAccounts++),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" <<
		this->_amount << ";created" << std::endl;
	return ;
}

Account::Account(int initial_deposit):
	_accountIndex(Account::_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";amount:" <<
		this->_amount << ";created" << std::endl;
	return ;
}

Account::~Account(void)
{
	// Maybe remove the current Account info from the statics
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" <<
		this->_amount << ";closed" << std::endl;
	return ;
}

// Function member
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int		p_amount = this->_amount;
	bool	accecpted = withdrawal < this->_amount;

	if (accecpted)
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
	}

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:";
	if (!accecpted)
		std::cout << "refused" << std::endl;
	else
		std::cout << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;

	return (accecpted);
}

void	Account::makeDeposit(int deposit)
{
	int	p_ammount = this->_amount;
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_ammount
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
	return ;
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	return ;
}

// Static Function member
// __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm		*local_time = std::localtime(&now);
	char		timestamp[32];

	strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", local_time);
	std::cout << '[' << timestamp << "] ";
	return ;
}
