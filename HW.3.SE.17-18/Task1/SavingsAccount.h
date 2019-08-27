#pragma once
#include "Account.h"

class SavingsAccount : public Account 
{
	double interestRate;
public:
	SavingsAccount(string IBAN = "", unsigned int OwnerId = 0, double InterestRate = 0);
	virtual void deposit(double Sum) override;
	virtual bool withdraw(double Sum) override;
	virtual void display() const override;
	double getInterestRate() const;
	void setInterestRate(double IR);
};
