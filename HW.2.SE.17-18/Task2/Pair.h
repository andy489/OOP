#pragma once
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template<typename T>
class Pair
{
	char* key = nullptr;
	T value;
public:
	Pair()
	{
		setKey("");
	}

	Pair(const char* key, T value)
	{
		setKey(key);
		setValue(value);
	}

	Pair& operator=(const Pair& p)
	{
		if (this != &p)
		{
		setKey(p.getKey());
		setValue(p.getValue());
		}
		return *this;		
	}

	Pair(const Pair& p)
	{
		*this = p;
	}

	~Pair()
	{
		delete[] this->key;
	}

	const char* getKey()const
	{
		return this->key;
	}

	T getValue()const
	{
		return this->value;
	}

	void setKey(const char* key)
	{
		delete[] this->key;
		size_t len = strlen(key) + 1;
		this->key = new char[len];
		strcpy_s(this->key, len, key);
	}

	void setValue(T value)
	{
		this->value = value;
	}
	template<class T>
	friend ostream& operator<<(ostream& os, const Pair<T>& p);

};

template<class T>
ostream & operator<<(ostream & os, const Pair<T>& p)
{
	os << p.getKey() << " " << p.getValue() << endl;

	return os;
}
