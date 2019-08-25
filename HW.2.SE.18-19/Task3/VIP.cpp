#include "VIP.h"

VIP::VIP() {}

VIP::VIP(const char * ip,
	const char * username,
	const char * pass,
	const char * title) :User(ip, username, pass, title) {}

void VIP::setTitle(const char* title)
{
	if (strcmp(this->title, title) == 0)
	{
		cout << "New title must be different from current title!" << endl
			<< "------------------------------------------" << endl;
	}
	else if (strcmp(this->title, title) != 0)
	{
		delete[] this->title;
		size_t len = strlen(title) + 1;
		this->title = new char[len];
		strcpy_s(this->title, len, title);
	}
}

void VIP::print() const
{
	cout << "IP address of VIP user is: " << getIp() << endl
		<< "Username of VIP user is: " << getUsername() << endl
		<< "Password of VIP user is: " << getPass() << endl
		<< "Title of VIP user is: " << getTitle() << endl
		<< "------------------------------------------" << endl;
}
