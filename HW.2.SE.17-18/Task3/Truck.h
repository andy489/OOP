#pragma once
#include <iostream>
#include "Vehicle.h"

class Truck : public Vehicle
{
private:
protected:
	int size;
public:
	Truck(string Make = "", string Model = "",
		string Color = "", int Year = 0,
		int Mileage = 0, int Length = 0);
	int getSize() const;
	void setSize(int Meters);
	void details() const override;
};
