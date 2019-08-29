#pragma once
#include "RestaurantItem.h"

class Drink : public RestaurantItem
{
	enumType type;
	std::string name;
	double alc;

public:
	Drink();
	Drink(const unsigned quantity, const double price, const std::string name, const double alc);
	
	bool operator>(const Drink& d);

	const std::string getName()const;
	const double getAlc()const;

	void setName(const std::string name);
	void setAlc(const double grams);

	virtual RestaurantItem* clone() const;

	const std::string typeToStr() const;

	virtual void print() const override;
};
