/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarbois <mdarbois@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:44:29 by mdarbois          #+#    #+#             */
/*   Updated: 2023/10/12 15:44:29 by mdarbois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstring>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
  Account::_nbAccounts++;
	Account::_totalAmount += _amount;
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";" << "created" << std::endl;
}

Account::~Account(void)	{
  std::string lines[8];

	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";" << "closed" << std::endl;
  Account::_nbAccounts--;
}

int	Account::getNbAccounts(void) {
  return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
  return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
  return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals(void) {
  return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	std::time_t result = std::time(NULL);

    std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&result)->tm_year
                << std::setw(2) << 1 + std::localtime(&result)->tm_mon
                <<  std::setw(2) << std::localtime(&result)->tm_mday
                <<  "_"
                <<  std::setw(2) << std::localtime(&result)->tm_hour
                <<  std::setw(2) << std::localtime(&result)->tm_min
                <<  std::setw(2) << std::localtime(&result)->tm_sec 
                << "] " << std::flush;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";" << "p_amount:" << this->_amount << ";" << "deposit:";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout	<< deposit << ";" << "amount:" << this->_amount << ";" << "nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";" << "p_amount:" << this->_amount << ";" << "withdrawal:";
	if (withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	else {
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout	<< withdrawal << ";" << "amount:" << this->_amount << ";" << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< "index:"	<< this->_accountIndex << ";"	<< "amount:"	<< this->_amount << ";"	<< "deposits:"	<< this->_nbDeposits << ";"	<< "withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout	<< "accounts:"<< getNbAccounts() << ";"	<< "total:"	<< getTotalAmount()	<< ";"	<< "deposits:"	<< getNbDeposits() << ";"	<< "withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}
