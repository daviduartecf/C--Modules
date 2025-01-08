/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:38:25 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/13 23:26:08 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>

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
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
    Account::_nbAccounts --;
}

Account::Account() {
    _nbAccounts += 1;
    _accountIndex = _nbAccounts - 1;
    std::cout << "Created account with: 0 " << std::endl;
}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
    Account::_totalAmount += _amount;
    Account::_nbAccounts += 1;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts - 1;
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

void	Account::displayStatus( void ) const {
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" <<  _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	now;

	now = time(NULL);
	std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}

void    Account::makeDeposit(int deposit) {
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

int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}