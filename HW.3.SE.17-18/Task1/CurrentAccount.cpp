#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(string IBAN, unsigned int OwnerId) :
	Account(IBAN, OwnerId)
{
	accountType = AccountType::CurrentAcc;
}

void CurrentAccount::deposit(double Sum)
{
	amount += Sum;
}

bool CurrentAccount::withdraw(double Sum)
{
	if (Sum <= amount)
	{
		amount -= Sum;
		return true;
	}
	return false;
}

void CurrentAccount::display() const
{
	cout << "Account type: " << AccTypeToStr(accountType) << endl
		<< "IBAN: " << iban << endl
		<< "Owner ID: " << ownerId << endl
		<< "Balance: " << amount << endl;
}
