#include "PowerUser.h"

PowerUser::PowerUser()
{
	this->reputation = 0;
}

PowerUser::PowerUser(const char * ip,
	const char * username,
	const char * pass,
	const char * title) :User(ip, username, pass, title) {}

void PowerUser::incrementReputation(const User& u)
{
	if (strcmp(this->username, u.getUsername()) != 0)
	{
		reputation++;
		cout << u.getUsername() << " gave you +1 reputation" << endl
			<< "------------------------------------------" << endl;
	}
	else if (strcmp(this->username, username) == 0)
	{
		cout << "Cannot give reputation to yourself!" << endl
			<< "------------------------------------------" << endl;
	}
}

const int PowerUser::getReputation() const
{
	return this->reputation;
}

void PowerUser::print() const
{
	cout << "IP address of PowerUser is: " << getIp() << endl
		<< "Username of PowerUser is: " << getUsername() << endl
		<< "Password of PowerUser is: " << getPass() << endl
		<< "Title of PowerUser is: " << getTitle() << endl
		<< "Reputation of PowerUser is: " << getReputation() << endl
		<< "------------------------------------------" << endl;
}
