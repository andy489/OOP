#pragma once
#include <iostream>

class BankAccount
{
	double balance;
	double limit;

	void copy(const BankAccount& acc);

public:

	BankAccount();
	BankAccount(double balance,double limit);
	BankAccount(const BankAccount& b);
	BankAccount& operator=(const BankAccount& b);
	
	void setBalance(double money);
	const double getBalance()const;

	void setLimit(double money);
	const double getLimit()const;

	bool payment(double money); // плащане

	void incaso(double money); // внасяне на пари
	bool withdraw(double money); // теглене на пари

	void displayBalance() const; // принтира само баланса
	void displayAccount() const;
};
