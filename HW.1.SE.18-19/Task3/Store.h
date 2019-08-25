#pragma once
#include "Product.h"

class Store
{   //private by default
	Product** products=nullptr;
	size_t size = 0;
	size_t cap = 0;

	void incrementSize();
	void decrementSize();

	void incrementCap();
	int getCap()const;

	void resize();

public:

	size_t getSize()const;

	void addProduct(const Product&);
	bool removeProduct(const size_t index);
	bool changeProduct(unsigned int, const Product&);
	void printStore()const;

	~Store();
};
