#include "Bank.h"

size_t Bank::indexCustomer(unsigned int Id)
{
	for (size_t i = 0; i < customers.size(); i++)
	{
		if (customers[i].getId() == Id)
		{
			return i;
		}
	}
	return -1;
}

size_t Bank::indexAccount(std::string Iban)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIBAN() == Iban) return i;
	}
	return -1;
}

size_t Bank::indexAccount(unsigned int CustomerId)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getOwnerId() == CustomerId) return i;
	}
	return -1;
}

void Bank::copyAccounts(std::vector<Account*> accs)
{
	Account* tmp;
	for (size_t i = 0; i < accs.size(); i++)
	{
		if (accs[i]->getType() == CurrentAcc)
		{
			tmp = new CurrentAccount((const CurrentAccount&)accs[i]);
			accounts.push_back(tmp);
		}
		else if (accs[i]->getType() == SavingsAcc)
		{
			tmp = new SavingsAccount((const SavingsAccount&)accs[i]);
			accounts.push_back(tmp);
		}
		else if (accs[i]->getType() == PrivilegeAcc)
		{
			tmp = new PrivilegeAccount((const PrivilegeAccount&)accs[i]);
			accounts.push_back(tmp);
		}
		else
		{
			cout << "Unknown account found at index " << i << ". Terminating copying.\n";
			break;
		}
	}

}

Bank::Bank(const Bank & B) : name(B.name), address(B.address)
{
	copyAccounts(B.accounts);
	for (size_t i = 0; i < B.customers.size(); i++)
	{
		customers.push_back(customers[i]);
	}
}

Bank & Bank::operator=(const Bank & B)
{
	if (this != &B) 
	{
		for (size_t i = 0; i < accounts.size(); i++)
		{
			delete accounts[i];
		}
		copyAccounts(B.accounts);
		for (size_t i = 0; i < B.customers.size(); i++)
		{
			customers.push_back(customers[i]);
		}
	}
	return *this;
}

Bank::Bank(std::string Name, std::string Address)
	: name(Name), address(Address) {}

Bank::~Bank()
{
	for (size_t i = 0; i < accounts.size(); i++) 
	{
		delete accounts[i];
	}
}

std::string Bank::getName() const
{
	return name;
}

std::string Bank::getAddress() const
{
	return address;
}

void Bank::addCustomer(unsigned int CustomerId, string Name, string Address)
{
	if (indexCustomer(CustomerId) != (size_t)-1) 
	{
		cout << "~Failed to add customer, the id " << CustomerId << " is already in use.\n";
		return;
	}
	Customer newCustomer(CustomerId, Name, Address);
	customers.push_back(newCustomer);
	cout << "~Added customer " << CustomerId << " successfully.\n";
}

void Bank::listCustomers() const
{
	for (size_t i = 0; i < customers.size(); i++) 
	{
		customers[i].display();
		cout << endl;
	}
}

void Bank::deleteCustomer(unsigned int CustomerId)
{
	// Security check
	size_t customer = indexCustomer(CustomerId);
	if (customer == (size_t)-1) 
	{
		cout << "~No customer with id " << CustomerId << " exists.\n";
		return;
	}

	// Remove all his accounts
	size_t index = indexAccount(CustomerId);
	while (index != (size_t)-1) 
	{   // Deleting all accounts of the customer
		deleteAccount(accounts[index]->getIBAN());
		index = indexAccount(CustomerId);
	}

	// Remove the customer
	customers.erase(customers.begin() + customer);
	cout << "~Deleted customer " << CustomerId << " successfully.\n";
}

void Bank::addAccount(AccountType AccType, string IBAN, unsigned int OwnerId, double Amount)
{
	// Security checks
	size_t customerPos = indexCustomer(OwnerId);
	if (customerPos == (size_t)-1) 
	{	// Check if a customer with this id already exists
		cout << "~Failed to add account. Customer with id " << OwnerId << " does not exist.\n";
		return;
	}
	size_t accountPos = indexAccount(IBAN);
	if (accountPos != (size_t)-1)
	{	// Check if an account with this IBAN already exists
		cout << "~Failed to add account. Account with IBAN " << IBAN << " already exists.\n";
		return;
	}

	// Create the appropriate account
	Account* acc;
	if (AccType == CurrentAcc) acc = new CurrentAccount(IBAN, OwnerId);
	else if (AccType == SavingsAcc) acc = new SavingsAccount(IBAN, OwnerId);
	else if (AccType == PrivilegeAcc) acc = new PrivilegeAccount(IBAN, OwnerId);
	else 
	{
		cout << "~Cannot add an account of unknown type.\n";
		return;
	}

	// Add the account
	acc->deposit(Amount);
	accounts.push_back(acc);
	cout << "~Added account " << IBAN << " successfully.\n";
}

void Bank::deleteAccount(string IBAN)
{
	size_t index = indexAccount(IBAN);
	if (index == (size_t)-1) 
	{
		std::cout << "~No account with IBAN " << IBAN << " exists.\n";
		return;
	}
	delete accounts[index];
	accounts.erase(accounts.begin() + index);
	cout << "~Deleted account " << IBAN << " successfully.\n";
}

void Bank::listAccounts() const
{
	for (size_t i = 0; i < accounts.size(); i++) 
	{
		cout << "-----\n";
		accounts[i]->display();
		cout << "-----\n";
	}
	cout << endl;
}

void Bank::listCustomerAccounts(unsigned int CustomerId) const
{
	bool printedOne = false;
	for (size_t i = 0; i < accounts.size(); i++) 
	{
		if (accounts[i]->getOwnerId() == CustomerId) 
		{
			cout << "-----\n";
			accounts[i]->display();
			cout << "-----\n";
			printedOne = true;
		}
	}
	// Extra check if the user has any accounts or exists
	if (!printedOne) 
	{
		cout << "~No customer with id " << CustomerId << " exists or he has no accounts.\n";
	}
}

void Bank::transfer(std::string fromIBAN, string toIBAN, double amount)
{
	// Security checks
	size_t from = indexAccount(fromIBAN);
	size_t to = indexAccount(toIBAN);
	if (from == (size_t)-1 || to == (size_t)-1) 
	{
		cout << "~Transfer failed. No accounts with such IBANs exist.\n";
		return;
	}
	// Try to withdraw
	if (!accounts[from]->withdraw(amount)) 
	{
		cout << "~Transfer failed. Failed to withdraw the desired amount from " << fromIBAN << ".\n";
		return;
	}
	accounts[to]->deposit(amount);
	cout << "~Transaction successful.\n";
}

void Bank::display() const
{
	std::cout << "Bank " << name << " located at " << address << "." << endl
		<< "~Number of Customers: " << customers.size() << ". Number of Accounts: " << accounts.size() << ".\n";
}

bool Bank::getAccountByIBAN(string IBAN, Account* &Acc)
{
	size_t index = indexAccount(IBAN);
	if (index == (size_t)-1) return false;
	Acc = accounts[index];
	return true;
}
