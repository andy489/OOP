#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(string IBAN, unsigned int OwnerId, double InterestRate) :
	Account(IBAN, OwnerId), interestRate(InterestRate)
{
	accountType = AccountType::SavingsAcc;
}

void SavingsAccount::deposit(double Sum)
{
	amount += Sum;
}

bool SavingsAccount::withdraw(double Sum)
{
	if (Sum <= amount)
	{
		amount -= Sum;
		return true;
	}
	return false;
}

void SavingsAccount::display() const
{
	cout << "Account type: " << AccTypeToStr(accountType) << endl
		<< "IBAN: " << iban << endl
		<< "Owner ID: " << ownerId << endl
		<< "Balance: " << amount << endl
		<< "Interest Rate: " << interestRate << endl;
}

double SavingsAccount::getInterestRate() const
{
	return interestRate;
}

void SavingsAccount::setInterestRate(double IR)
{
	interestRate = IR;
}
