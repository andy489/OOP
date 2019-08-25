#pragma once
#include "VIP.h"
#include "PowerUser.h"

class Admin : public VIP, public PowerUser
{
public:
	Admin();
	Admin(const char* ip,
		const char* username,
		const char* pass,
		const char* title);
	void setUsername(const char* username);
	void setUsernameOfUser(User & u, const char* newUsername);

	void print()const;
};
