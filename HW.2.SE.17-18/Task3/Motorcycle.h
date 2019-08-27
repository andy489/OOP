#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle 
{
private:
protected:
	string type;
public:
	Motorcycle(string Make = "", string Model = "", string Color = "", 
		int Year = 0, int Mileage = 0, string Type = "");
	void setType(string Type);
	string getType() const;
	void details() const override;
};
