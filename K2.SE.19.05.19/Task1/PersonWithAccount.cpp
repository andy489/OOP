#include "PersonWithAccount.h"

PersonWithAccount::PersonWithAccount()
{
	setIBAN("");
}

PersonWithAccount::PersonWithAccount(
	const char * name,
	const char * egn,
	size_t age,
	size_t birthYear,
	double balance,
	double limit,
	const char* IBAN) :
	Person(name, egn, age, birthYear),
	BankAccount(balance,limit)
{
	setIBAN(IBAN);
}

PersonWithAccount::PersonWithAccount(Person& p, BankAccount& a,const char* IBAN):Person(p), BankAccount(a)
{
	setIBAN(IBAN);
}

PersonWithAccount::PersonWithAccount(const PersonWithAccount & p) :
	Person(p), BankAccount(p)
{
	setIBAN(p.getIBAN());
}

PersonWithAccount & PersonWithAccount::operator=(const PersonWithAccount & p)
{
	if (this != &p)
	{
		Person::operator=(p);
		BankAccount::operator=(p);
		setIBAN(p.getIBAN());
	}
	return *this;
}

PersonWithAccount::~PersonWithAccount()
{
	delete[] this->IBAN;
}

bool PersonWithAccount::spotify()
{
	if (payment(10))
	{
		std::cout << "Name: " << getName() << "\n"
			<< "IBAN: " << getIBAN() << "\n"
			<< "New Balance: " << getBalance() << "\n"
			<< "----------------FiBank----------------\n\n";
		return true;
	}
	else
	{
		std::cout << "Not enough money to make a Spotify registration.\n\n";
		return false;
	}

}

bool PersonWithAccount::setIBAN(const char* IBAN)
{
	bool checkIBAN = true;
	for (size_t i = 0; i < 10; i++)
	{
		if (IBAN[i] > '9' || IBAN[i] < '0')
		{
			checkIBAN = false;
			break;
		}
	}
	if (strlen(IBAN) == 10 && checkIBAN)
	{
		delete[]this->IBAN;
		size_t len = strlen(IBAN) + 1;
		this->IBAN = new char[len];
		strcpy_s(this->IBAN, len, IBAN);
		return true;
	}
	else
	{
		std::cout << "Invalid IBAN!\nEnter valid (10 digit) IBAN : ";
		char IBAN[256];
		std::cin >> IBAN;
		setIBAN(IBAN);
	}
	return true; //nvm
}

const char* PersonWithAccount::getIBAN() const
{
	return this->IBAN;
}

void PersonWithAccount::print() const
{
	Person::print();
	BankAccount::displayBalance();
	std::cout << "IBAN: " << getIBAN() << "\n"
		<< "------------FiBank------------\n\n";
}
