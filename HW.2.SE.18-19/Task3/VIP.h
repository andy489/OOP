#pragma once
#include "User.h"

class VIP :virtual public User
{
public:
	VIP();
	VIP(const char* ip,
		const char* username,
		const char* pass,
		const char* title);
	void setTitle(const char* title);

	void print()const;
};
