#include "ElectricNet.h"

ElectricNet::ElectricNet(unsigned int MaxPower) : maxPower(MaxPower), currentPower(0) {}

ElectricNet& ElectricNet::operator+(const ElectricDevice& ED) 
{
	unsigned int t = ED.getPower();
	if (ED.getPower() + currentPower <= maxPower) 
	{
		list.add(ED);
		currentPower += ED.getPower();
	}
	return *this;
}
void ElectricNet::operator+=(const ElectricDevice& ED) 
{
	operator+(ED);
}
ElectricNet& ElectricNet::operator-(const ElectricDevice& ED) 
{
	size_t tmpN = list.Size();
	list.removeAt(list.Index(ED));
	if (list.Size() != tmpN) currentPower -= ED.getPower();// If an item was removed
		
	return *this;
}
void ElectricNet::operator-=(const ElectricDevice& ED) 
{
	operator-(ED);
}
ElectricDevice& ElectricNet::operator[](const char* Str) 
{
	return list[list.Index(ElectricDevice(0, Str))];
}
ElectricNet::operator bool() const
{
	return list.Size() != 0;
}
ElectricNet& ElectricNet::operator++() 
{
	maxPower *= 2;
	return *this;
}
ElectricNet ElectricNet::operator++(int) 
{
	ElectricNet tmp(*this);
	operator++();
	return tmp;
}
ElectricNet& ElectricNet::operator--() 
{
	if (maxPower >= currentPower * 2) maxPower /= 2;
	return *this;
}
ElectricNet ElectricNet::operator--(int) 
{
	ElectricNet tmp(*this);
	operator--();
	return tmp;
}
unsigned int ElectricNet::CurrentPower() const 
{
	return currentPower;
}
unsigned int ElectricNet::MaxPower() const 
{
	return maxPower;
}
size_t ElectricNet::DevicesNumber() const 
{
	return list.Size();
}
