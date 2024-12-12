#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
	std::string accountNumber;
	double balance;

public:
	Account(std::string accNumber, double initialBalance);

	void deposit(double amount);
	bool withdraw(double amount);
	double getBalance() const;
	std::string getAccountNumber() const;

	~Account() {}
};

#endif