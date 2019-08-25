#include "Store.h"

void Store::incrementSize()
{
	this->size++;
}

void Store::decrementSize()
{
	if (getSize() > 0) this->size--;
}

void Store::incrementCap()
{
	if (getCap() == 0) this->cap = 2;
	else this->cap *= 2;
}

int Store::getCap() const
{
	return this->cap;
}

void Store::resize()
{
	incrementCap();
	Product** newProducts = new Product*[getCap()];

	for (size_t i = 0; i < getSize(); i++) newProducts[i] = products[i];

	delete[] products;
	products = newProducts;
}

size_t Store::getSize() const
{
	return this->size;
}

void Store::addProduct(const Product &p)
{
	if (getSize() == getCap()) resize();
	incrementSize();

	products[getSize() - 1] = new Product(p);
}

bool Store::removeProduct(const size_t index)
{
	if (index >= getSize())	return 0;
	else
	{
		delete products[index];
		for (size_t i = index; i < getSize() - 1; i++) products[i] = products[i + 1];
		decrementSize();
		return 1;
	}
}

bool Store::changeProduct(unsigned int index, const Product& p)
{
	if (index >= getSize()) return 0;
	else
	{
		delete products[index];
		products[index] = new Product(p);
		return 1;
	}
}

void Store::printStore() const
{
	for (size_t i = 0; i < getSize(); i++) products[i]->print();
}

Store::~Store()
{
	for (size_t i = 0; i < getSize(); i++) delete products[i];
	delete[] products;
}
