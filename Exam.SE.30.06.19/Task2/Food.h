#pragma once
#include "RestaurantItem.h"

class Food : public RestaurantItem
{
	enumType type;
	std::string name;
	double grams;

public:
	Food();
	Food(const unsigned quantity, const double price, const std::string name, const double grams);

	bool operator>(const Food& f);

	const std::string getName()const;
	const double getGrams()const;

	void setName(const std::string name);
	void setGrams(const double grams);

	virtual RestaurantItem* clone() const;

	const std::string typeToStr() const;

	virtual void print() const override;
};
