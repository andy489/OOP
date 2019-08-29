#include "Drink.h"

Drink::Drink() :RestaurantItem()
{
	type = enumType::DRINK;
	setName("");
	setAlc(0);
}

Drink::Drink(const unsigned quantity, const double price,
	const std::string name, const double alc) :
	RestaurantItem(quantity, price)
{
	setName(name);
	setAlc(alc);
	type = enumType::DRINK;
}

bool Drink::operator>(const Drink& d)
{
	return (this->getAlc() > d.getAlc());
}

const std::string Drink::getName() const
{
	return this->name;
}

const double Drink::getAlc() const
{
	return this->alc;
}

void Drink::setName(const std::string name)
{
	this->name = name;
}

void Drink::setAlc(const double alc)
{
	this->alc = alc;
}

RestaurantItem* Drink::clone() const
{
	return new Drink(*this);
}

const std::string Drink::typeToStr() const
{
	return "DRINK";
}

void Drink::print() const
{
	std::cout << "Type: " << typeToStr() << "\nName: " << getName() <<
		"\nAlcohol: " << getAlc() << "%\n";
	RestaurantItem::print();
	std::cout << "\n";
}
