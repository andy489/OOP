#pragma once
#include <iostream>

extern unsigned int SKU;

class Product
{	//private by default
	unsigned int currSKU;
	char* brand = nullptr;
	char* model = nullptr;
	double price;
	unsigned int count;

	void copy(const Product& p);

public:

	Product();
	Product(const char* brand, const char* model, const double price, const unsigned int count);
	Product(const Product&);
	Product& operator=(const Product&);

	const unsigned int getSKU()const;
	void incrementSKU();

	const char* getBrand()const;
	void setBrand(const char*);

	const char* getModel()const;
	void setModel(const char*);

	const double getPrice()const;
	void setPrice(double);

	const unsigned int getCount()const;
	void setCount(unsigned int);

	void print()const;

	~Product();
};
