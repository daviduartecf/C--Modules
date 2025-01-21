/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:38:25 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/21 13:10:01 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" <<  Account::getTotalAmount() << ";";
    std::cout << "deposits:" <<  Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" <<  Account::getNbWithdrawals() << std::endl;
}

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

Account::~Account() {
	Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
    Account::_nbAccounts --;
}

Account::Account() {
	Account::_displayTimestamp();
    _nbAccounts += 1;
    _accountIndex = _nbAccounts - 1;
    std::cout << "Created account with: 0 " << std::endl;
}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	Account::_displayTimestamp();
    Account::_totalAmount += _amount;
    Account::_nbAccounts += 1;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts - 1;
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" <<  _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	char buffer[20];

	now = std::time(NULL);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", std::localtime(&now));
	std::cout << buffer;
}

void    Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
    if (deposit > 0)
    {
        _nbDeposits ++;
        Account::_totalNbDeposits++;
	    Account::_totalAmount += deposit;
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "p_amount:" << _amount << ";";
        _amount += deposit;
        std::cout << "deposit:" << deposit << ";";
        std::cout << "amount:" << _amount << ";";
        std::cout << "nb_deposits:" << _nbDeposits << ";" << std::endl;
    }
}

bool    Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
    if (withdrawal > 0)
    {
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "p_amount:" << _amount << ";";
        if (_amount > withdrawal)
        {
            _nbWithdrawals ++;
            Account::_totalNbWithdrawals++;
            Account::_totalAmount -= withdrawal;
            _amount -= withdrawal;
            std::cout << "withdrawal:" << withdrawal << ";";
            std::cout << "amount:" << _amount << ";";
            std::cout << "nb_withdrawals:" << _nbWithdrawals << ";" << std::endl;
        }
        else
        {
            std::cout << "withdrawal:refused" << std::endl;
            return (false);
        }
    }
    return (true);
}
