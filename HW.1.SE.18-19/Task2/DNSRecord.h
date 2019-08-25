#pragma once
#include <iostream>
#include <string>
using namespace std;

class DNSRecord
{
	char* domainName = nullptr;
	char* ipAddress = nullptr;

	void copy(const DNSRecord& r);
public:
	DNSRecord();
	DNSRecord(const DNSRecord& r);
	~DNSRecord();

	void setDomainName(const char* domainName);
	void setIpAddress(const char* ipAddress);

	const char* getDomainName()const;
	const char* getIpAddress()const;

	DNSRecord& operator=(const DNSRecord& r);

	friend ostream& operator<<(ostream& os, const DNSRecord& r);
	friend istream& operator>>(istream& is, DNSRecord& r);
};
