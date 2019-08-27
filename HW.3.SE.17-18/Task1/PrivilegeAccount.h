#pragma once
#include "Account.h"

class PrivilegeAccount : public Account 
{
	double overdraft;
public:
	PrivilegeAccount(string IBAN = "", unsigned int OwnerId = 0, double Overdraft = 0);
	virtual void deposit(double Sum) override;
	virtual bool withdraw(double Sum) override;
	virtual void display() const override;
	double getOverdraft() const;
	void setOverdraft(double Overdraft);
};
