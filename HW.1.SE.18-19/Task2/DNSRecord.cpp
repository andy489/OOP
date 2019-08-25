#include "DNSRecord.h"

void DNSRecord::copy(const DNSRecord & r)
{
	setDomainName(r.getDomainName());
	setIpAddress(r.getIpAddress());
}

DNSRecord::DNSRecord()
{
	setDomainName("n/n");
	setIpAddress("n/n");
}

DNSRecord::DNSRecord(const DNSRecord &r)
{
	copy(r);
}

DNSRecord::~DNSRecord()
{
	delete[] this->domainName;
	delete[] this->ipAddress;
}

void DNSRecord::setDomainName(const char * domainName)
{
	delete[] this->domainName;
	size_t len = strlen(domainName) + 1;
	this->domainName = new char[len];
	strcpy_s(this->domainName, len, domainName);
}

void DNSRecord::setIpAddress(const char * ipAddress)
{
	delete[] this->ipAddress;
	size_t len = strlen(ipAddress) + 1;
	this->ipAddress = new char[len];
	strcpy_s(this->ipAddress, len, ipAddress);
}

const char * DNSRecord::getDomainName() const
{
	return this->domainName;
}

const char * DNSRecord::getIpAddress() const
{
	return this->ipAddress;
}

DNSRecord & DNSRecord::operator=(const DNSRecord &r)
{
	copy(r);
	return *this;
}

ostream & operator<<(ostream &os, const DNSRecord &p)
{
	os << "Domain Name: " << p.getDomainName() << endl
		<< "IP address: " << p.getIpAddress() << endl
		<< "------------------------------------------------" << endl;
	return os;
}

istream & operator>>(istream &is, DNSRecord &p)
{
	char strInput[255];

	is >> strInput;
	p.setDomainName(strInput);

	is >> strInput;
	p.setIpAddress(strInput);

	return is;
}
