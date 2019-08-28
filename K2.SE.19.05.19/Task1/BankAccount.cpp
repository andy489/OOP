#include "BankAccount.h"

void BankAccount::copy(const BankAccount& acc)
{
	setBalance(acc.getBalance());
	setLimit(acc.getLimit());
}

BankAccount::BankAccount()
{
	this->balance = 0;
	this->limit = 0;
}

BankAccount::BankAccount(double balance, double limit)
{
	setBalance(balance);
	setLimit(limit);
}

BankAccount::BankAccount(const BankAccount& acc)
{
	copy(acc);
}

BankAccount & BankAccount::operator=(const BankAccount& acc)
{
	if (this != &acc)
	{
		copy(acc);
	}
	return *this;
}

void BankAccount::setBalance(double balance)
{
	this->balance = balance;
}

const double BankAccount::getBalance() const
{
	return this->balance;
}

void BankAccount::setLimit(double money)
{
	this->limit = money;
}

const double BankAccount::getLimit() const
{
	return this->limit;
}


bool BankAccount::payment(double payment)
{
	double balance = getBalance();
	double limit = getLimit();

	if (balance + limit >= payment)
	{
		setBalance(balance - payment);
		std::cout << "PAYMENT: " << payment << " lv." << "\n"
			<< "------------FiBank------------" << "\n\n";
		return true;
	}
	else
	{
		std::cout << "Not enough money for payment.\n"		
		<< "------------FiBank------------" << "\n\n";
		return false;
	}
}

void BankAccount::incaso(double money)
{
	double balance = getBalance();
	setBalance(balance + money);
	std::cout << money << " lv. deposited" << "\n"
		<< "------------FiBank------------" << "\n\n";
}

bool BankAccount::withdraw(double money)
{
	double balance = getBalance();
	if (balance - money < 0)
	{
		std::cout << "You have no such funds available" << "\n"
			<< "------------FiBank------------" << "\n\n";
		return false;

	}
	else
	{
		setBalance(balance - money);
		std::cout << "PAYMENT: " << money << " lv." << "\n"
			<< "------------FiBank------------" << "\n\n";
		return true;
	}
}


void BankAccount::displayBalance() const
{
	std::cout << "Current balance: " << getBalance() << " lv.\n";
}

void BankAccount::displayAccount() const
{
	std::cout << "Current balance: " << getBalance() << " lv.\n"
		<< "Limit: " << getLimit() << " lv.\n\n";
}
