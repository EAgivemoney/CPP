#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "BankService.h"
#include <iostream>

class Customer : public Person, public BankService {
private:
	double balance;

public:
	Customer(std::string name, int id, double initialBalance)
		: Person(name, id), balance(initialBalance) {}

	void deposit(double amount) override {
		balance += amount;
		std::cout << "Deposited: $" << amount << "\n";
	}

	void withdraw(double amount) override {
		if (amount <= balance) {
			balance -= amount;
			std::cout << "Withdrawn: $" << amount << "\n";
		}
		else {
			std::cout << "Insufficient funds.\n";
		}
	}

	void displayBalance() const override {
		std::cout << "Balance: $" << balance << "\n";
	}

	void displayInfo() const override {
		std::cout << "Customer ID: " << id << ", Name: " << name << "\n";
		displayBalance();
	}
};

#endif