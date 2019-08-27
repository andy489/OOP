#pragma once
#include "Vehicle.h"

class Car : public Vehicle 
{
private:
public:
	Car(string Make = "", string Model = "", string Color = "", 
		int Year = 0, int Mileage = 0);
	void details() const override;
};
