#pragma once

template <typename T>
class Sorted
{
	T* arr;
	int length;
	int capacity;
public:
	Sorted();
	Sorted(T* arr, int length);
	Sorted(Sorted<T> const& arr);
	~Sorted();
	Sorted<T>& operator=(Sorted<T> const& arr);
	bool operator==(const Sorted<T>& other) const;
	T operator[](int index) const;
	void AddElement(T& element);
	void RemoveElement(T& element);
	void Print() const;
	int IndexOf(const T&) const;
	int Length() const
	{
		return this->length;
	}
};

template <typename T>
Sorted<T>::Sorted()
{
	arr = nullptr;
	length = 0;
	capacity = 0;
}

template <typename T>
Sorted<T>::Sorted(T* arr, int length)
{
	this->length = 0;
	this->arr = nullptr;
	for (int i = 0; i < length; ++i)
	{
		this->AddElement(arr[i]);
	}
}

template <typename T>
Sorted<T>::Sorted(Sorted<T> const& arr)
{
	this->length = arr.length;
	this->arr = new T[arr.length];
	for (int i = 0; i < length; ++i)
	{
		this->arr[i] = arr.arr[i];
	}
	this->capacity = arr.capacity;
}

template <typename T>
Sorted<T>::~Sorted()
{
	delete[] arr;
}

template <typename T>
Sorted<T>& Sorted<T>::operator=(Sorted<T> const& arr)
{
	this->length = arr.length;
	delete[] this->arr;
	this->arr = new T[arr.length];
	for (int i = 0; i < arr.length; ++i)
	{
		this->arr[i] = arr.arr[i];
	}
	this->capacity = arr.capacity;
	return *this;
}

template <typename T>
void Sorted<T>::AddElement(T& element)
{
	int index = 0;
	for (int i = 0; i < this->length; i++)
	{
		if (this->arr[i] < element)
		{
			index++;
			continue;
		}
		break;
	}
	if (this->capacity == 0)
	{
		this->arr = new T[1];
		this->capacity++;
		this->arr[0] = element;
		this->length++;
		return;
	}
	T* temp = this->arr;

	this->arr = new T[++this->capacity];

	for (int i = 0; i < index; i++)
	{
		this->arr[i] = temp[i];
	}
	this->arr[index] = element;
	for (int i = index + 1; i < this->length + 1; i++)
	{
		this->arr[i] = temp[i - 1];
	}

	delete[] temp;

	this->length++;
}

template <typename T>
void Sorted<T>::Print() const
{
	std::cout << "Array: ";
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void Sorted<T>::RemoveElement(T& element)
{
	if (this->length >= 1)
	{
		int count = 0;
		for (int i = 0; i < this->length; ++i)
		{
			if (this->arr[i] == element)
			{
				count++;
			}
		}
		T* tmp = new T[this->length - count];
		for (int i = 0, j = 0; i < this->length; ++i, ++j)
		{
			if (this->arr[i] == element)
			{
				tmp[j] = this->arr[++i];
			}
			else
			{
				tmp[j] = this->arr[i];
			}
		}
		delete[] this->arr;
		this->arr = tmp;
		this->length = this->length - count;
	}
	else
	{
		return;
	}
}

template <typename T>
bool Sorted<T>::operator==(const Sorted<T>& other) const
{
	if (this->length != other.length)
	{
		return false;
	}
	for (int i = 0; i < this->length; i++)
	{
		if (!(this->arr[i] == other.arr[i]))
		{
			return false;
		}
	}
	return true;
}

template <typename T>
int Sorted<T>::IndexOf(const T& element) const
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->arr[i] == element)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
T Sorted<T>::operator[](int index) const
{
	return this->arr[index];
}

