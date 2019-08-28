#pragma once
#include "Person.h"
#include "BankAccount.h"
class PersonWithAccount :public Person, public BankAccount
{
	char* IBAN = nullptr;

public:

	PersonWithAccount();
	PersonWithAccount(const char* name,
		const char* egn,
		size_t age,
		size_t birth,
		double balance,
		double limit,
		const char* IBAN);
	PersonWithAccount(Person& p, BankAccount& a,const char* IBAN);
	PersonWithAccount(const PersonWithAccount& p);
	PersonWithAccount&operator=(const PersonWithAccount& p);
	~PersonWithAccount();

	bool spotify();

	bool setIBAN(const char* IBAN);
	const char* getIBAN() const;
	
	void print()const;
};
