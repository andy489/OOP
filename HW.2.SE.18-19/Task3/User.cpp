#include "User.h"

void User::setUsername(const char * username)
{
	delete[] this->username;
	size_t len = strlen(username) + 1;
	this->username = new char[len];
	strcpy_s(this->username, len, username);
}

void User::setPass(const char * pass)
{
	delete[] this->pass;
	size_t len = strlen(pass);
	this->pass = new char[len + 1];
	// encrypting pass
	for (size_t i = 0; i < len; i++)
	{
		this->pass[i] = pass[i] + 1;
	}
	this->pass[len] = '\0';
}

void User::setTitle(const char * title)
{
	delete[] this->title;
	size_t len = strlen(title) + 1;
	this->title = new char[len];
	strcpy_s(this->title, len, title);
}

const char * User::getUsername() const
{
	return this->username;
}

const char * User::getPass() const
{
	return this->pass;
}

const char * User::getTitle() const
{
	return this->title;
}

User::User() :Guest()
{
	setUsername("");
	setPass("");
	setTitle("");
}

User::User(const char * ip,
	const char * username,
	const char * pass,
	const char * title) :Guest(ip)
{
	setUsername(username);
	setPass(pass);
	setTitle(title);
}

User::~User()
{
	delete[] this->username;
	delete[] this->pass;
	delete[] this->title;
}

bool User::changePass(const char * prevPass, const char * newPass)
{
	size_t lenPrevPass = strlen(prevPass);
	size_t lenPass = strlen(this->pass);
	if (lenPrevPass != lenPass)
	{
		cout << "Password not changed!" << endl
			<< "------------------------------------------" << endl;
		return false;
	}
	else
	{
		for (size_t i = 0; i < lenPass; i++)
		{
			//decrypting pass
			if (this->pass[i] - 1 != prevPass[i])
			{
				cout << "Password not changed!" << endl
					<< "------------------------------------------" << endl;
				return false;
			}
		}
		setPass(newPass);
		return true;
	}
}

void User::print() const
{
	cout << "IP address of USER is: " << getIp() << endl
		<< "Username of USER is: " << getUsername() << endl
		<< "Password of USER is: " << getPass() << endl
		<< "Title of USER is: " << getTitle() << endl
		<< "------------------------------------------" << endl;
}
