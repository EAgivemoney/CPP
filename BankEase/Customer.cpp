#include "Customer.h"
#include <iostream>

Customer::Customer(std::string name, int id, double initialBalance)
	: Person(name, id), balance(initialBalance) {}

void Customer::deposit(double amount) {
	balance += amount;
	std::cout << "Deposited: $" << amount << "\n";
}

void Customer::withdraw(double amount) {
	if (amount <= balance) {
		balance -= amount;
		std::cout << "Withdrawn: $" << amount << "\n";
	}
	else {
		std::cout << "Insufficient funds.\n";
	}
}

void Customer::displayBalance() const {
	std::cout << "Balance: $" << balance << "\n";
}

void Customer::displayInfo() const {
	std::cout << "Customer ID: " << id << ", Name: " << name << "\n";
	displayBalance();
}