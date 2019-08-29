#include "Food.h"

Food::Food() :RestaurantItem()
{
	type = enumType::FOOD;
	setName("");
	setGrams(0);
}

Food::Food(const unsigned quantity, const double price,
	const std::string name, const double grams) :
	RestaurantItem(quantity, price)
{
	setName(name);
	setGrams(grams);
	type = enumType::FOOD;
}

bool Food::operator>(const Food & f)
{
	return (this->getGrams() > f.getGrams());
}

const std::string Food::getName() const
{
	return this->name;
}

const double Food::getGrams() const
{
	return this->grams;
}

void Food::setName(const std::string name)
{
	this->name = name;
}

void Food::setGrams(const double grams)
{
	this->grams = grams;
}

RestaurantItem* Food::clone() const
{
	return new Food(*this);
}

const std::string Food::typeToStr() const
{
	return "FOOD";
}

void Food::print() const
{
	std::cout << "Type: " << typeToStr() << "\nName: "
		<< getName() << "\nGrams: " << getGrams() << "\n";
	RestaurantItem::print();
	std::cout << "\n";
}
