#pragma once
#include "ElectricDevice.h"
#include "List.h"

class ElectricNet 
{
private:
	unsigned int maxPower;
	List<ElectricDevice> list;
	unsigned int currentPower;
public:
	ElectricNet(unsigned int Power = 0);
	void operator+=(const ElectricDevice& ED);
	ElectricNet& operator+(const ElectricDevice& ED);
	ElectricNet& operator-(const ElectricDevice& ED);
	void operator-=(const ElectricDevice& ED);
	ElectricDevice& operator[](const char* Str);
	operator bool() const;
	ElectricNet& operator++();
	ElectricNet operator++(int);
	ElectricNet& operator--();
	ElectricNet operator--(int);
	unsigned int CurrentPower() const;
	unsigned int MaxPower() const;
	size_t DevicesNumber() const;
};
