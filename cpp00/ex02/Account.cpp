#include <ctime>
#include <iostream>
#include "Account.hpp"

void Account::_displayTimestamp()
{
	std::time_t currentTime = std::time(nullptr);
    struct tm* localTime = std::localtime(&currentTime);

    std::cout << "[" << localTime->tm_year + 1900 << localTime->tm_mon + 1 << localTime->tm_mday;
    std::cout << "_" << localTime->tm_hour << localTime->tm_min << localTime->tm_sec << "]";
}

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount = _totalAmount + initial_deposit;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
			<< ";amount:" << _amount \
			<< ";created" << std::endl;
}
