#include "Admin.h"

Admin::Admin() {}

Admin::Admin(const char * ip,
	const char * username,
	const char * pass,
	const char * title) : User(ip, username, pass, title) {}

void Admin::setUsername(const char * username)
{
	if (strcmp(this->username, username) == 0)
	{
		cout << "New username must be different from current username!" << endl
			<< "------------------------------------------" << endl;
	}
	else if (strcmp(this->username, username) != 0)
	{
		delete[] this->username;
		size_t len = strlen(username) + 1;
		this->username = new char[len];
		strcpy_s(this->username, len, username);
	}
}

void Admin::setUsernameOfUser(User & u, const char* newUsername)
{
	if (strcmp(newUsername, u.getUsername()) == 0)
	{
		cout << "New username must be different from current username!" << endl
			<< "------------------------------------------" << endl;
	}
	else if (strcmp(newUsername, u.getUsername()) != 0)
	{
		delete[] u.username;
		size_t len = strlen(newUsername) + 1;
		u.username = new char[len];
		strcpy_s(u.username, len, newUsername);
	}
}

void Admin::print() const
{
	cout << "IP address of Admin is: " << getIp() << endl
		<< "Username of Admin is: " << getUsername() << endl
		<< "Password of Admin is: " << getPass() << endl
		<< "Title of Admin is: " << getTitle() << endl
		<< "Reputation of Admin is: " << getReputation() << endl
		<< "------------------------------------------" << endl;
}
