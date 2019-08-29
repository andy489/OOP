#pragma once
#include "RestaurantItem.h"
#include "Food.h"
#include "Drink.h"
#include <vector>

class Restaurant
{
	std::vector <RestaurantItem*> items;

public:

	Restaurant();
	Restaurant(const Restaurant& r);
	Restaurant& operator=(const Restaurant& r);
	~Restaurant();

	void addItem(RestaurantItem* item);
	bool eraseItem(const unsigned index);

	void printAllProducts()const;
	void printAllNonAlcDrinks() const;
};
