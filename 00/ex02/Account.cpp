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

Account::Account(int initial_deposit):
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts++;

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

void	Account::_displayTimestamp(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);

	std::cout << '[' << tv.tv_sec << tv.tv_usec / 1000 << "] ";

	return ;
}
