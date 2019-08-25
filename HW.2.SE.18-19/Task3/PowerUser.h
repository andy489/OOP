#pragma once
#include "User.h"

class PowerUser :virtual public User
{
protected:
	int reputation;
public:
	PowerUser();
	PowerUser(const char* ip,
		const char* username,
		const char* pass,
		const char* title);

	void incrementReputation(const User& u);
	const int getReputation()const;

	void print() const;
};
