#include "Bank.h"

void MemoryTest()
{
	Bank b("Fi Bank", "Sofia, Central");

	cout << "Bank info:\n";
	b.display();

	cout << "Adding customers:\n";
	b.addCustomer(2, "Ivan", "Sofia 1");
	b.addCustomer(2, "George", "Sofia 2"); // Fails to add because the id already exists
	cout << endl;

	cout << "Listing customers:\n";
	b.listCustomers(); // 1 Customer in the list

	cout << "Adding customers:\n";
	b.addCustomer(3, "George", "Sofia 2");
	cout << std::endl;

	cout << "Listing customers:\n";
	b.listCustomers(); // 2 Customers in the list
	cout << std::endl;

	cout << "Adding accounts:\n";
	b.addAccount(CurrentAcc, "BG02", 2, 0);
	b.addAccount(CurrentAcc, "BG02", 2, 15.00); // Fails because that IBAN already exists
	b.addAccount(CurrentAcc, "BG03", 1, 15.00); // Fails because user with id 1 does not exist
	b.addAccount(SavingsAcc, "BG03", 3, 300.00);
	b.addAccount(PrivilegeAcc, "BG021", 2, 2500.00);
	b.addAccount(PrivilegeAcc, "BG022", 2, 3.14);
	cout << endl;

	cout << "Listing accounts:\n";
	b.listAccounts(); // 4 accounts

	cout << "Showing accounts of user 2:\n";
	b.listCustomerAccounts(2);

	cout << "Deleting accounts:\n";
	b.deleteAccount("BG033"); // Fails as no such IBAN is in the list
	b.deleteAccount("BG021");
	cout << endl;

	cout << "Bank info:\n";
	b.display(); // 3 accounts as 1 has been deleted

	cout << "Transfers:\n";
	b.transfer("FakeIBAN", "BG02", 2500); // Fails because the IBAN is invalid
	b.transfer("BG03", "BG02", 2500); // Fails because the amount is invalid
	b.transfer("BG03", "BG02", 200); // Succeeds
	cout << endl;

	cout << "Showing accounts of user 2:\n";
	b.listCustomerAccounts(2);

	cout << "Deleting customers:\n";
	b.deleteCustomer(35); // Fails because no customer with id 35 exists
	b.deleteCustomer(2);
	cout << endl;

	cout << "Showing accounts of user 2:\n";
	b.listCustomerAccounts(2); // Fails as this customer is deleted
}

int main()
{
	//MemoryTest();

	Bank s("Super-Cool-Bank-100", "No-man's-land");

	std::string help("\
lc = List Customers\n\
ac = Add Customer\n\
dc = Delete Customer\n\
lac = List All Accounts\n\
lca = List Customer accounts\n\
aa = Add Account\n\
da = Delete Account\n\
wa = Withdraw from Account\n\
dia = Deposit to Account\n\
t = Transfer\n\
i = Display info for the bank\n\
q = Quit\n\
h = Help\n");
	cout << help;
	string input;
	while (true) 
	{
		cin >> input;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Clean stream
		
		if (input == "lc") 
		{
			s.listCustomers();
		}
		else if (input == "ac") 
		{
			cout << "Enter customer ID: ";
			getline(cin, input);
			string tmp1;
			string tmp2;
			cout << "Enter customer Name: ";
			getline(std::cin, tmp1);
			cout << "Enter customer Address: ";
			getline(cin, tmp2);
			s.addCustomer(stoi(input), tmp1, tmp2);
		}
		else if (input == "dc") 
		{
			cout << "Enter customer (id) to delete: ";
			getline(cin, input);
			s.deleteCustomer(stoi(input));
		}
		else if (input == "lac") 
		{
			s.listAccounts();
		}
		else if (input == "lca") 
		{
			cout << "Enter user to list accounts of: ";
			getline(cin, input);
			s.listCustomerAccounts(stoi(input));
		}
		else if (input == "aa") 
		{
			cout << "Enter account type to add (1 for Current, 2 for Savings, 3 for Privilege): ";
			getline(std::cin, input);
			string tmp1;
			string tmp2;
			string tmp3;
			cout << "Enter IBAN: ";
			getline(cin, tmp1);
			cout << "Enter OwnerId: ";
			getline(cin, tmp2);
			cout << "Enter Amount: ";
			getline(cin, tmp3);
			s.addAccount((AccountType)std::stoi(input), tmp1, stoi(tmp2), stod(tmp3));
		}
		else if (input == "da") 
		{
			cout << "Enter account IBAN to delete: ";
			getline(cin, input);
			s.deleteAccount(input);
		}
		else if (input == "wa") 
		{
			cout << "Enter account IBAN to withdraw from: ";
			getline(cin, input);
			string tmp;
			cout << "Enter sum to withdraw: ";
			getline(cin, tmp);
			Account * acc = nullptr;
			if (s.getAccountByIBAN(input, acc)) 
			{   // If the account is found
				acc->withdraw(stoi(tmp));
			}
		}
		else if (input == "dia") 
		{
			cout << "Enter account IBAN to deposit to: ";
			getline(cin, input);
			string tmp;
			cout << "Enter sum to deposit: ";
			getline(cin, tmp);
			Account * acc = nullptr;
			if (s.getAccountByIBAN(input, acc)) 
			{	// If the account is found
				acc->deposit(stoi(tmp));
			}
		}
		else if (input == "t") 
		{
			cout << "Enter account to transfer to: ";
			getline(cin, input);
			string tmp1;
			string tmp2;
			cout << "Enter account to transfer from: ";
			getline(cin, tmp1);
			cout << "Enter ammount: ";
			getline(cin, tmp2);
			s.transfer(tmp1, input, stod(tmp2));
		}
		else if (input == "i") s.display();		
		else if (input == "q") break;		
		else if (input == "h") cout << help;
		else cout << "Ivanlid input, try h.\n";		
	}
	return 0;
}
