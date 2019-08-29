#include "RestaurantItem.h"

RestaurantItem::RestaurantItem() :quantity(0), price(0) {}

RestaurantItem::RestaurantItem(const unsigned quantity, const double price)
{
	setQuantity(quantity);
	setPrice(price);
}

void RestaurantItem::setQuantity(const unsigned quantity)
{
	this->quantity = quantity;
}

void RestaurantItem::setPrice(const double price)
{
	this->price = price;
}

const unsigned RestaurantItem::getQuantity() const
{
	return this->quantity;
}

const double RestaurantItem::getPrice() const
{
	return this->price;
}

void RestaurantItem::print() const
{
	std::cout << "Quantity: " << getQuantity() <<
		"\nPrice: " << getPrice() << "\n";
}
