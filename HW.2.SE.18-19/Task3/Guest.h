#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Guest
{
private:

protected:
	char* ip = nullptr;
	void setIp(const char* ip);
	const char* getIp() const;
public:
	Guest();
	Guest(const char* ip);
	~Guest();

	void print()const;
};
