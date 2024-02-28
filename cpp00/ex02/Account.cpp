#include <ctime>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

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

int	Account::checkAmount( void ) const
{
	if (_amount < 0)
		return (0);
	return (1);
}

void Account::_displayTimestamp()
{
	const std::time_t currentTime = std::time(nullptr);
    const struct tm* localTime = std::localtime(&currentTime);

    std::cout << "[" << localTime->tm_year + 1900 << localTime->tm_mon + 1 << localTime->tm_mday;
    std::cout << "_" << localTime->tm_hour << localTime->tm_min << localTime->tm_sec << "]";
}

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;

    _accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount = _totalAmount + initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n";
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::makeDeposit(int deposit )
{
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits <<"\n";
	_totalNbDeposits++; 
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	amountTemp = _amount;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	_amount -= withdrawal;
	if (!checkAmount()) {
		_amount = amountTemp;
		std::cout << "refused\n";
		return (false);
	}
	else {
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
		_totalAmount -= withdrawal;
	}
	
	return (true);
}

Account::~Account( void ) {
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}
