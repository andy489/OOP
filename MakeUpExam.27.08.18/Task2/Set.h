#pragma once
#include <iostream>

template<typename T>
class Set
{
	T* arr = nullptr;
	size_t size;
	size_t cap;

	void copy(const Set& set);

	void incrementSize();
	void decrementSize();

	void resize();

	bool isEmpty() const;
	bool isFull() const;

public:

	Set();
	Set(const Set& set);
	Set<T>& operator=(const Set& set);
	~Set();
	T operator[](const size_t index) const;

	void setSize(const size_t size);
	void setCap(const size_t cap);

	const size_t getSize() const;
	const size_t getCap() const;

	void insert(const T& element);
	bool contains(const T& element) const;
	bool erase(const size_t index);

	Set<T> unite(const Set<T>& set);
	Set<T> intersect(const Set<T>& set);

	void display() const;
};

template<typename T>
inline void Set<T>::copy(const Set & set)
{
	setSize(set.getSize());
	setCap(set.getCap());

	arr = new T[set.getCap()];

	for (size_t i = 0; i < set.getSize(); i++)
	{
		arr[i] = set[i];
	}
}

template<typename T>
inline void Set<T>::incrementSize()
{
	this->size++;
}

template<typename T>
inline void Set<T>::decrementSize()
{
	this->size--;
}

template<typename T>
inline void Set<T>::resize()
{
	setCap(2 * getCap());

	T* newArr = new T[getCap()];
	for (size_t i = 0; i < getSize(); i++)
	{
		newArr[i] = arr[i];
	}

	delete[] this->arr;
	this->arr = newArr;
}

template<typename T>
inline bool Set<T>::isEmpty() const
{
	return (getSize() == 0);
}

template<typename T>
inline bool Set<T>::isFull() const
{
	return (getSize() == getCap());
}

template<typename T>
inline Set<T>::Set()
{
	size = 0;
	cap = 4;
	arr = new T[cap];
}

template<typename T>
inline Set<T>::Set(const Set & set)
{
	copy(set);
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set & set)
{
	if (this != &set)
	{
		delete[] arr;
		copy(set);
	}
	return *this;
}

template<typename T>
inline Set<T>::~Set()
{
	delete[] arr;
}

template<typename T>
inline T Set<T>::operator[](const size_t index) const
{
	if (index > getSize() || index < 0)
	{
		return T();
	}
	return arr[index];
}

template<typename T>
inline void Set<T>::setSize(const size_t size)
{
	this->size = size;
}

template<typename T>
inline void Set<T>::setCap(const size_t cap)
{
	this->cap = cap;
}

template<typename T>
inline const size_t Set<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline const size_t Set<T>::getCap() const
{
	return this->cap;
}

template<typename T>
inline void Set<T>::insert(const T& element)
{
	if (!contains(element))
	{
		if (isFull()) resize();
		incrementSize();
		arr[getSize() - 1] = element;
	}
}

template<typename T>
inline bool Set<T>::contains(const T& element) const
{
	size_t n = getSize();
	for (size_t i = 0; i <n ; i++)
	{
		if (arr[i] == element || arr[n - i - 1] == element)
		{
			return true;
		}
	}
	return false;
}

template<typename T>
inline bool Set<T>::erase(const size_t index)
{
	if (index > getSize() || index < 0)
	{
		return false;
	}
	if (isEmpty())
	{
		return false;
	}
	for (size_t i = index; i < getSize() - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	decrementSize();
}

template<typename T>
inline Set<T> Set<T>::unite(const Set<T>& set)
{
	Set<T> united(set);
	for (size_t i = 0; i < getSize(); i++)
	{
		united.insert(this->arr[i]);
	}
	return united;
}

template<typename T>
inline Set<T> Set<T>::intersect(const Set<T>& set)
{
	Set<T> intersected;
	for (size_t i = 0; i < set.getSize(); i++)
	{
		if (contains(set[i]))
		{
			intersected.insert(set[i]);
		}
	}
	return intersected;
}

template<typename T>
inline void Set<T>::display() const
{
	for (size_t i = 0; i < getSize(); i++)
	{
		if (i == getSize() - 1)
		{
			std::cout << this->arr[i];
			break;
		}
		std::cout << this->arr[i] << ", ";
	}
	std::cout << "\n\n";
}
