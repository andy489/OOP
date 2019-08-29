#pragma once
#include "Enums.h"

class RestaurantItem
{
protected:

	unsigned quantity;
	double price;

public:

	RestaurantItem();
	RestaurantItem(const unsigned quantity, const double price);

	void setQuantity(const unsigned quantity);
	void setPrice(const double price);

	const unsigned getQuantity() const;
	const double getPrice() const;

	virtual RestaurantItem* clone() const = 0;

	virtual void print() const;

};
