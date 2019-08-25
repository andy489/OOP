#pragma once
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class MagicBox
{
	T* items = nullptr;

	size_t size = 0;
	size_t count = 0;

	void setSize(size_t newSize);
	void setCount(size_t newCount);

	void incrementCount();
	void decrementCount();

public:

	size_t getSize() const;
	size_t getCount() const;

	void insert(T item);
	const T pop();

	void list() const;

	~MagicBox();
};

template<typename T>
void MagicBox<T>::setSize(size_t newSize)
{
	this->size = newSize;
}

template<typename T>
void MagicBox<T>::setCount(size_t newCount)
{
	this->count = newCount;
}

template<typename T>
void MagicBox<T>::incrementCount()
{
	this->count++;
}

template<typename T>
void MagicBox<T>::decrementCount()
{
	this->count--;
}

template<typename T>
MagicBox<T>::~MagicBox()
{
	delete[] this->items;
}

template<typename T>
size_t MagicBox<T>::getSize() const
{
	return this->size;
}

template<typename T>
size_t MagicBox<T>::getCount() const
{
	return this->count;
}

template<typename T>
void MagicBox<T>::insert(T item)
{
	if (getCount() >= getSize())
	{
		if (getCount() == 0)
		{
			setSize(4);
			this->items = new T[getSize()];
		}
		else
		{
			setSize(2 * getSize());
			T* newItems = new T[getSize()];
			for (size_t i = 0; i < getCount(); i++)
			{
				newItems[i] = this->items[i];
			}
			delete[] this->items;
			this->items = newItems;
		}
	}
	items[getCount()] = item;
	incrementCount();
}

template<typename T>
const T MagicBox<T>::pop()
{
	if (getCount())
	{
		size_t randomNumber = rand() % getCount();
		T poppedItem = items[randomNumber];
		decrementCount();
		items[randomNumber] = items[getCount()];
		cout << "Mag-O-Kodersky threw into the air: ";
		return poppedItem;
	}
	else
	{
		cout << "The box is empty!" << endl
			<< "---------------------------------------------" << endl;
		return {};
	}
}

template<typename T>
void MagicBox<T>::list() const
{
	cout << "Items in Mag-O-Kodersky's Magic Box: " << endl;
	for (size_t i = 0; i < getCount(); i++)
	{
		cout << i + 1 << ". " << this->items[i] << endl;
	}
	cout << "---------------------------------------------" << endl;
}
