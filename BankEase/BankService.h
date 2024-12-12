#ifndef BANKSERVICE_H
#define BANKSERVICE_H

class BankService {
public:
	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount) = 0;
	virtual void displayBalance() const = 0;
	virtual ~BankService() {}
};

#endif