#include "ElectricDevice.h"

ElectricDevice::ElectricDevice(unsigned int power, String name) : power(power), name(name) {}
String ElectricDevice::getName() const 
{
	return this->name;
}
void ElectricDevice::setName(String name) 
{
	this->name = name;
}
unsigned int ElectricDevice::getPower() const 
{
	return this->power;
}
void ElectricDevice::setPower(unsigned int power) 
{
	this->power = power;
}
bool ElectricDevice::operator==(const ElectricDevice& ED) const 
{
	return name == ED.name;
}
