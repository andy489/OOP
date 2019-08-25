#include "DNSCache.h"

void DNSCache::incrementSize()
{
	this->size++;
}

void DNSCache::decrementSize()
{
	this->size--;
}

void DNSCache::resize()
{
	DNSRecord* newRecords = new DNSRecord[getSize() + 1];

	for (size_t i = 0; i < getSize(); i++)
		newRecords[i] = this->records[i];

	delete[] this->records;
	this->records = newRecords;
	incrementSize();
}

DNSCache::DNSCache() {}

DNSCache::DNSCache(const DNSCache &c)
{
	*this = c;
}

DNSCache::~DNSCache()
{
	delete[] this->records;
}

const size_t DNSCache::getSize() const
{
	return this->size;
}

void DNSCache::add(const DNSRecord &r)
{
	resize();
	this->records[getSize() - 1] = r;
}

bool DNSCache::del(size_t index)
{
	if (index >= getSize())return false;	
	
	for (size_t i = index; i < getSize()-1; i++)
		this->records[i] = this->records[i + 1];
	decrementSize();
	cout << "ITEM " << index + 1 << " DELETED\n";
	return true;
}

void DNSCache::print() const
{
	cout << "CACHE CONTENTS:\n------------------------------------------------\n";
	for (size_t i = 0; i < getSize(); i++) cout << records[i];
}

void DNSCache::printIp(DNSRecord &r) const
{
	cout << r.getIpAddress() << endl;
}

void DNSCache::flush()
{
	while (getSize())
	{
		del(getSize());
		decrementSize();
	}
}

void DNSCache::lookup(const char *domainName)
{
	for (size_t i = 0; i < getSize(); i++)
	{
		if (!strcmp(domainName, records[i].getDomainName()))
		{
			printIp(records[i]);
			return;
		}
		else
		{
			if (i == getSize() - 1)
			{
				cout << "NULL" << endl;
				return;
			}
			continue;
		}
	}
}

DNSCache & DNSCache::operator=(const DNSCache &c)
{
	if (this != &c)
	{
		delete[] this->records;

		for (size_t i = 0; i < c.getSize(); i++)
			this->add(c[i]);
	}
	return *this;
}

void DNSCache::operator+=(const DNSRecord &p)
{
	add(p);
}

DNSRecord DNSCache::operator[](const size_t index) const
{
	if (index >= getSize()) return DNSRecord();
	else return records[index];
}
