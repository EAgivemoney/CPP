#include "Account.h"
#include <iostream>

Account::Account(std::string accNumber, double initialBalance) 
	: accountNumber(accNumber), balance(initialBalance) {}

void Account::deposit(double amount) {
	balance += amount;
	std::cout << "Deposited: $" << amount << " to account " << accountNumber << "\n";
}

bool Account::withdraw(double amount) {
	if (amount <= balance) {
		balance -= amount;
		std::cout << "Withdrawn: $" << amount << " from account " << accountNumber << "\n";
		return true;
	}
	else {
		std::cout << "Insufficient funds in account " << accountNumber << "\n";
		return false;
	}
}

double Account::getBalance() const {
	return balance;
}

std::string Account::getAccountNumber() const {
	return accountNumber;
}