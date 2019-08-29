#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Matrix
{
	T** elements;

	unsigned rows;
	unsigned cols;

	void copy(const Matrix<T>* &m);

public:

	Matrix(); // default constructor
	Matrix(const unsigned rows, const unsigned cols);  // constructor with parameters
	Matrix(const Matrix<T>* &m); // copy constructor
	Matrix<T> & operator=(const Matrix<T>& m); // operator =
	~Matrix(); // destructor

	void setRows(const unsigned rows);
	void setCols(const unsigned rows);

	const unsigned getRows()const;
	const unsigned getCols()const;

	void setAt(const unsigned x, const unsigned y, const T element);
	T getAt(const unsigned x, const unsigned y)const;
	void transpose();

	void print()const;

};

template<typename T>
inline void Matrix<T>::copy(const Matrix<T>*& m)
{
	setRows(m.getRows);
	setCols(m.getCols);
	for (unsigned i = 0; i < getRows(); i++)
	{
		for (unsigned j = 0; j < getCols(); j++)
		{
			elements[i][j] = m.elements[i][j];
		}
	}
}

template<typename T>
inline Matrix<T>::Matrix()
{
	elements = new T*[2];
	for (unsigned i = 0; i < 2; i++)
	{
		elements[i] = new T[2];
	}
	setRows(2);
	setCols(2);
}

template<typename T>
inline Matrix<T>::Matrix(const unsigned rows, const unsigned cols)
{

	elements = new T*[rows];
	for (unsigned i = 0; i < rows; i++)
	{
		elements[i] = new T[cols];
	}
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < cols; j++)
		{
			elements[i][j] = T();
		}
	}
	setRows(rows);
	setCols(cols);
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T>* &m)
{
	copy(m);
}

template<typename T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m)
{
	copy(m);
	return *this;
}

template<typename T>
inline Matrix<T>::~Matrix()
{

}

template<typename T>
inline void Matrix<T>::setRows(const unsigned rows)
{
	this->rows = rows;
}

template<typename T>
inline void Matrix<T>::setCols(const unsigned cols)
{
	this->cols = cols;
}

template<typename T>
inline const unsigned Matrix<T>::getRows() const
{
	return this->rows;
}

template<typename T>
inline const unsigned Matrix<T>::getCols() const
{
	return this->cols;
}

template<typename T>
inline void Matrix<T>::setAt(const unsigned x, const unsigned y, const T element)
{
	unsigned rows = getRows();
	unsigned cols = getCols();
	if (x > 0 && y > 0 && x <= rows && y <= cols)
	{
		elements[x - 1][y - 1] = element;
	}
	else
	{
		cout << "There is no such position in the matrix\n";
	}
}

template<typename T>
inline T Matrix<T>::getAt(const unsigned x, const unsigned y) const
{
	unsigned rows = getRows();
	unsigned cols = getCols();
	if (x > 0 && y > 0 && x <= rows && y <= cols)
	{
		return elements[x - 1][y - 1];
	}
	return T();
}

template<typename T>
inline void Matrix<T>::transpose()
{
	unsigned rows = getRows();
	unsigned cols = getCols();

	T** trans = new T*[cols];
	for (unsigned i = 0; i < cols; i++)
	{
		trans[i] = new T[rows];
	}
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < cols; j++)
		{
			trans[j][i] = elements[i][j];
		}
	}
	delete[] this->elements;
	setRows(cols);
	setCols(rows);
	this->elements = trans;
}

template<typename T>
inline void Matrix<T>::print() const
{
	size_t rows = getRows();
	size_t cols = getCols();
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << elements[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

