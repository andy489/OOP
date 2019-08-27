#include "Customer.h"

Customer::Customer(unsigned int ID, string Name, string Address)
	: name(Name), address(Address), id(ID) {}

unsigned int Customer::getId() const
{
	return id;
}

string Customer::getName() const
{
	return name;
}

string Customer::getAddress() const
{
	return address;
}

void Customer::display() const
{
	cout << "Customer " << name << " (" << id << ") " << "Address: " << address;
}
