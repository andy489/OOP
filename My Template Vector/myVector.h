#pragma once
#include <iostream>

template <typename T>
class myVector
{
	T *arr;
	unsigned size;
	unsigned cap;

	void incrementSize();
	void decrementSize();

	void incrementCap();
	void decrementCap();

	void resize();
	void copy(const myVector &v);

public:

	void setSize(const unsigned size);
	void setCap(const unsigned cap);

	unsigned getSize()const;
	unsigned getCap()const;

	//constructors
	myVector<T>(); //default
	myVector(unsigned size); //with parameter
	myVector(const myVector &v); //copy constructor

	myVector& operator=(const myVector &v); //operator =
	const T operator[](unsigned n); // operator []

	void pushBack(const T element);
	const T popBack();

	bool insert(unsigned pos, const T val);
	bool remove(unsigned pos);

	void setElement(unsigned pos, const T val);
	const T getElement(unsigned pos);

	const T begin() const;
	const T end() const;

	template <typename T>
	friend std::ostream& operator<<(std::ostream& os, const myVector<T>& v);
	friend std::istream& operator>>(std::istream& is, myVector& v);

	void printVec() const;
	~myVector(); // destructor
};



template <typename T>
void myVector<T>::incrementSize()
{
	this->size++;
}
template <typename T>
void myVector<T>::decrementSize()
{
	this->size--;
}
template <typename T>
void myVector<T>::incrementCap()
{
	this->cap += cap;
}
template <typename T>
void myVector<T>::decrementCap()
{
	this->cap -= (cap / 2);
}
template <typename T>
void myVector<T>::resize()
{
	incrementCap();
	T *newArr = new T[cap];
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = newArr;
}
template <typename T>
void myVector<T>::copy(const myVector<T> & v)
{
	delete[]this->arr;
	this->size = v.getSize();
	this->cap = v.getCap();
	this->arr = new T[cap];
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] = v.arr[i];
	}
}
template <typename T>
myVector<T>::myVector() :size(0), cap(4)
{
	arr = new T[4]();
}
template <typename T>
myVector<T>::myVector(unsigned size)
{
	this->cap = size;
	this->size = size;
	int* arr = new T[size]();
	this->arr = arr;
}
template <typename T>
myVector<T>::myVector(const myVector<T> &v)
{
	copy(v);
}
template <typename T>
myVector<T>& myVector<T>:: operator=(const myVector<T> & v)
{
	if (this != &v)
	{
		copy(v);
	}
	return *this;
}
template <typename T>
const T myVector<T>::operator[](unsigned n)
{
	if (n < size)
	{
		return this->arr[n];
	}
	else
	{
		std::cout << "out of vector limits\n";
		return int();
	}
}
template <typename T>
void myVector<T>::setElement(unsigned pos, const  T val)
{
	if (pos <= size)
	{
		arr[pos] = val;
	}
	else
	{
		std::cout << "Invalid position\n";
	}
}
template <typename T>
const T myVector<T>::getElement(unsigned pos)
{
	if (pos < size)
	{
		return this->arr[pos];
	}
	else
	{
		std::cout << "Invalid position\n";
		return int();
	}
}
template <typename T>
const T myVector<T>::begin() const
{
	if (size != 0)
	{
		return arr[0];
	}
	else
	{
		std::cout << "Empty vector\n";
		return arr[0];
	}
}
template <typename T>
const T myVector<T>::end() const
{
	if (size != 0)
	{
		return arr[size - 1];
	}
	else
	{
		std::cout << "Empty vector\n";
		return arr[0];
	}
}
template <typename T>
void myVector<T>::setSize(const unsigned size)
{
	this->size = size;
}
template <typename T>
void myVector<T>::setCap(const unsigned cap)
{
	this->cap = cap;
}
template <typename T>
unsigned myVector<T>::getSize() const
{
	return this->size;
}
template <typename T>
unsigned myVector<T>::getCap() const
{
	return this->cap;
}
template <typename T>
void myVector<T>::pushBack(const T element)
{
	if (size == cap)
	{
		resize();
	}
	arr[size] = element;
	incrementSize();
}
template <typename T>
const T myVector<T>::popBack()
{
	if (size == 0)
	{
		std::cout << "Empty vector\n";
		return arr[0];
	}
	else
	{
		decrementSize();
		return arr[size];
	}
}
template <typename T>
bool myVector<T>::insert(unsigned pos, const T val)
{
	if (pos <= size)
	{
		if (size == cap)
		{
			resize();
		}
		for (size_t i = size; i > pos; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[pos] = val;
		incrementSize();
		return true;
	}
	return false;
}
template <typename T>
bool myVector<T>::remove(unsigned pos)
{
	if (pos < size)
	{
		for (size_t i = pos; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[pos + 1].~T(); //explicit call of destructor for class T;
		decrementSize();
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
void myVector<T>::printVec() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
template <typename T>
myVector<T>::~myVector()
{
	delete[] this->arr;
}
template <typename T>

std::ostream & operator<<(std::ostream & os, const myVector<T> & v)
{
	unsigned SIZE = v.getSize();
	for (size_t i = 0; i < SIZE; i++)
	{
		os << v.arr[i] << ' ';
	}
	os << '\n';
	return os;
}
template <typename T>
std::istream & operator>>(std::istream & is, myVector<T> & v)
{
	unsigned n;
	T element;
	std::cout << "\nWhat is the number of elements you would like to enter: ";
	is >> n;
	for (size_t i = 0; i < n; i++)
	{
		is >> element;
		v.pushBack(element);
	}
	return is;
}
