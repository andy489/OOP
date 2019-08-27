#pragma once
#include "Account.h"

class CurrentAccount : public Account 
{
public:
	CurrentAccount(string IBAN = "", unsigned int OwnerId = 0);
	virtual void deposit(double Sum) override;
	virtual bool withdraw(double Sum) override;
	virtual void display() const override;
};
