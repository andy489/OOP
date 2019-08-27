#include "Account.h"

string Account::AccTypeToStr(AccountType AT) const
{
	if (AT == CurrentAcc) return "Current Account";	
	else if (AT == SavingsAcc) return "Savings Account";
	else if (AT == PrivilegeAcc) return "Privilege Account";	
	else return "Unspecified Account";
}

Account::Account(string IBAN, unsigned int OwnerId) : 
	iban(IBAN), ownerId(OwnerId), amount(0), accountType(AccountType::General){}

Account::~Account(){}

double Account::getBalance() const
{
	return amount;
}

const string& Account::getIBAN() const
{
	return iban;
}

unsigned int Account::getOwnerId() const
{
	return ownerId;
}

AccountType Account::getType() const
{
	return accountType;
}

double Account::getAmount() const
{
	return amount;
}
