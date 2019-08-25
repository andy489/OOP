#include "Guest.h"

const char * Guest::getIp() const
{
	return this->ip;
}

void Guest::setIp(const char* ip)
{
	delete[] this->ip;
	size_t len = strlen(ip) + 1;
	this->ip = new char[len];
	strcpy_s(this->ip, len, ip);
}

Guest::Guest()
{
	setIp("");
}

Guest::Guest(const char * ip)
{
	setIp(ip);
}

Guest::~Guest()
{
	delete[] this->ip;
}

void Guest::print() const
{
	cout << "IP address of GUEST is: " << getIp() << endl
		<< "------------------------------------------" << endl;
}
