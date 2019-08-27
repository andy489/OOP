#pragma once
#include <iostream>
#include <string>
#include "Enums.h"

class Account 
{
protected:
	string iban;
	unsigned int ownerId;
	double amount;
	AccountType accountType;
	string AccTypeToStr(AccountType AT) const;
public:
	Account(string IBAN = "", unsigned int OwnerId = 0);
	virtual ~Account();
	virtual void deposit(double Sum) = 0;
	virtual bool withdraw(double Sum) = 0;
	virtual void display() const = 0;
	double getBalance() const;
	const string& getIBAN() const;
	unsigned int getOwnerId() const;
	AccountType getType() const;
	double getAmount() const;
};
