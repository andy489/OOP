#pragma once
#include "String.h"

class ElectricDevice 
{
private:
	String name;
	unsigned int power;
public:
	ElectricDevice(unsigned int Power = 0, String Name = "");
	String getName() const;
	void setName(String NewName);
	unsigned int getPower() const;
	void setPower(unsigned int NewPower);
	bool operator==(const ElectricDevice& ED) const;
};
