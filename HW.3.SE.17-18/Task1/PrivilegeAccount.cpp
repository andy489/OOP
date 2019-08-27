#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(string IBAN, unsigned int OwnerId, double Overdraft) :
	Account(IBAN, OwnerId), overdraft(Overdraft)
{
	accountType = AccountType::PrivilegeAcc;
}

void PrivilegeAccount::deposit(double Sum)
{
	amount += Sum;
}

bool PrivilegeAccount::withdraw(double Sum)
{
	if (Sum <= amount + overdraft) 
	{
		amount -= Sum;
		return true;
	}
	return false;
}

void PrivilegeAccount::display() const
{
	cout << "Account type: " << AccTypeToStr(accountType) << endl
		<< "IBAN: " << iban << std::endl
		<< "Owner ID: " << ownerId << endl
		<< "Balance: " << amount << endl
		<< "Overdraft: " << overdraft << endl;
}

double PrivilegeAccount::getOverdraft() const
{
	return overdraft;
}

void PrivilegeAccount::setOverdraft(double Overdraft)
{
	overdraft = Overdraft;
}
