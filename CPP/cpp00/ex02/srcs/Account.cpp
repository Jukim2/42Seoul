#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = getNbAccounts();
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
    _nbAccounts++;
    _totalAmount += _amount;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" <<  _accountIndex << ";";
    std::cout << "amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (Account::_totalNbWithdrawals);
}

void    Account::_displayTimestamp()
{
    time_t timer = time(NULL);
    struct  tm* t = localtime(&timer);

    std::cout << "[" << t->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_mday;
    std::cout << "_" << std::setw(2) << std::setfill('0') << t->tm_hour;
    std::cout << t->tm_min << t->tm_sec << "] ";
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" <<  _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    int p_amount = _amount;
    
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" <<  _accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    int p_amount = _amount;

    _displayTimestamp();
    std::cout << "index:" <<  _accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
        _amount -=withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << _amount << ";";
        std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
}
