#pragma once
#include "Customer.h"
#include "CurrentAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include <vector>

class Bank 
{
private:
	string name;
	string address;
	vector<Customer> customers;
	vector<Account*> accounts;
	size_t indexCustomer(unsigned int Id);
	size_t indexAccount(std::string Iban);
	size_t indexAccount(unsigned int CustomerId);
	void copyAccounts(std::vector<Account*> accs);
public:
	Bank(const Bank&);
	Bank& operator=(const Bank&);
	Bank(std::string Name, std::string Address = "");
	~Bank();
	std::string getName() const;
	std::string getAddress() const;
	void addCustomer(unsigned int CustomerId, std::string Name, std::string Address);
	void listCustomers() const;
	void deleteCustomer(unsigned int CustomerId);
	void addAccount(AccountType AccType, std::string IBAN, unsigned int OwnerId, double Amount);
	void deleteAccount(std::string IBAN);
	void listAccounts() const;
	void listCustomerAccounts(unsigned int CustomerId) const;
	void transfer(std::string fromIBAN, std::string toIBAN, double amount);
	void display() const;
	bool getAccountByIBAN(std::string IBAN, Account *& Acc);
};
