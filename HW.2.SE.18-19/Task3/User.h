#pragma once
#include "Guest.h"

class User :protected Guest
{
private:
	void setUsername(const char* ip);
	void setPass(const char* pass);
	void setTitle(const char* title);

	friend class Admin;

protected:
	char* username = nullptr;
	char* pass = nullptr;
	char* title = nullptr;

public:
	User();
	User(const char* ip,
		const char* username,
		const char* pass,
		const char* title);
	~User();

	const char* getUsername()const;
	const char* getPass()const;
	const char* getTitle()const;

	bool changePass(const char* prevPass, const char* newPass);

	void print() const;
};
