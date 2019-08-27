#pragma once
#include <iostream>
#include <string>
using namespace std;

class Customer 
{
	unsigned int id;
	string name;
	string address;
public:
	Customer(unsigned int ID = 0, string Name = "", string Address = "");
	unsigned int getId() const;
	string getName() const;
	string getAddress() const;
	void display() const;
};
