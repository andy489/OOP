#pragma once
#include "Pair.h"

template<class T>
class Settings
{
	Pair<T>* pairs = nullptr;
	int size = 0;

	const int getSize()const
	{
		return this->size;
	}

	void incrementSize()
	{
		this->size++;
	}

	void decrementSize()
	{
		this->size--;
	}

	void resize()
	{
		//правим нов списък с дължина равна на дължината на стария списък + 1
		Pair<T>* newPairs = new Pair<T>[getSize() + 1];
		//копираме в новия списък всички елементи от стария списък
		for (int i = 0; i < getSize(); i++)	newPairs[i] = this->pairs[i];
		//изтриваме стария списък
		delete[] this->pairs;
		//на мястото където е сочел стария списък слагаме новия списък
		this->pairs = newPairs;
		//инкрементираме размера, защото вече е с един елемент по-голям
		incrementSize();
	}

public:

	Settings()
	{
		this->pairs = nullptr;
		size = 0;
	}

	Settings<T>& operator=(const Settings<T>& s)
	{
		if (this == &s)	return *this; //оптимизация
		delete[] pairs;
		for (int i = 0; i < s.getSize(); i++) set(s.pairs[i].getKey(), s.pairs[i].getValue());
		return *this;
	}

	Settings(const Settings<T>& s)
	{
		*this = s;
	}

	~Settings()
	{
		delete[] pairs;
	}

	const size_t count() const
	{
		return getSize();
	}

	void set(const char* key, const T value)
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (strcmp(this->pairs[i].getKey(), key) == 0)
			{
				pairs[i].setValue(value);
				return;
			}
		}
		resize();
		pairs[getSize() - 1] = Pair<T>(key, value);
	}

	bool get(const char* key, T& out)
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (strcmp(this->pairs[i].getKey(), key) == 0)
			{
				out = pairs[i].getValue();
				return true;
			}
		}
		return false;
	}

	void print()const
	{
		cout << "Printing settings:\n";
		for (int i = 0; i < getSize(); i++)
		{
			cout << pairs[i];
		}
		cout << endl;
	}
};
