#include "Product.h"

unsigned int SKU = 1;

void Product::copy(const Product & p)
{
	setBrand(p.getBrand());
	setModel(p.getModel());
	setPrice(p.getPrice());
	setCount(p.getCount());
}

const unsigned int Product::getSKU() const
{
	return this->currSKU;
}

void Product::incrementSKU()
{
	this->currSKU = SKU;
	SKU++;
}

const char * Product::getBrand() const
{
	return this->brand;
}

void Product::setBrand(const char* brand)
{
	if (this->brand) delete[] this->brand;
	size_t len = strlen(brand) + 1;
	this->brand = new char[len];
	strcpy_s(this->brand, len, brand);
}

const char * Product::getModel() const
{
	return this->model;
}

void Product::setModel(const char* model)
{
	if (this->model) delete[] this->model;
	size_t len = strlen(model) + 1;
	this->model = new char[len];
	strcpy_s(this->model, len, model);
}

const double Product::getPrice() const
{
	return this->price;
}

void Product::setPrice(double price)
{
	this->price = price;
}

const unsigned int Product::getCount() const
{
	return this->count;
}

void Product::setCount(unsigned int count)
{
	this->count = count;
}

void Product::print() const
{
	std::cout << "SKU: " << getSKU() << std::endl
		<< "Brand: " << getBrand() << std::endl
		<< "Model: " << getModel() << std::endl
		<< "Price: " << getPrice() << std::endl
		<< "Count: " << getCount() << std::endl << std::endl;
}

Product::Product() :price(0), count(0)
{
	incrementSKU();
	setBrand("def");
	setModel("def");
}

Product::Product(const char * brand, const char * model, double price, const unsigned int count) :Product()
{
	setBrand(brand);
	setModel(model);
	setPrice(price);
	setCount(count);
}

Product::Product(const Product &p)
{
	this->currSKU = p.getSKU();
	copy(p);
}

Product & Product::operator=(const Product & p)
{
	if (this == &p) return*this;
	else copy(p);
	return *this;
}

Product::~Product()
{
	delete[] brand;
	delete[] model;
}
