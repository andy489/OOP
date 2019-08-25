#pragma once
#include "DNSRecord.h"

class DNSCache
{
	DNSRecord* records = nullptr;
	size_t size = 0;

	void incrementSize();
	void decrementSize();

	void resize();
public:
	DNSCache();
	DNSCache(const DNSCache&);
	~DNSCache();

	const size_t getSize() const;

	void add(const DNSRecord& r);
	bool del(size_t index);

	void print() const;
	void printIp(DNSRecord & r) const;
	void flush();
	void lookup(const char* domainName);

	DNSCache& operator=(const DNSCache& c);
	DNSRecord operator[](const size_t index) const;
	void operator+=(const DNSRecord& r);
};
