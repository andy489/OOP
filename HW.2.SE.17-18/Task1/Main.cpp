#include <iostream>
#include "ElectricDevice.h"
#include "ElectricNet.h"

void Test() 
{
	ElectricNet en(10);
	std::cout << "Devices: " << en.DevicesNumber() << " Power: " << en.CurrentPower() << "/" << en.MaxPower() << "\n";
	ElectricDevice a;
	a.setName("ElectricVehicle");
	a.setPower(5);
	ElectricDevice b(2, "Phone");
	en += a;
	en + b + b;
	std::cout << "Devices: " << en.DevicesNumber() << " Power: " << en.CurrentPower() << "/" << en.MaxPower() << "\n";
	en++;
	++en;
	std::cout << "Devices: " << en.DevicesNumber() << " Power: " << en.CurrentPower() << "/" << en.MaxPower() << "\n";
	en += a;
	--en;
	--en;
	std::cout << "Devices: " << en.DevicesNumber() << " Power: " << en.CurrentPower() << "/" << en.MaxPower() << "\n";
	en -= a;
	en - a;
	std::cout << "Devices: " << en.DevicesNumber() << " Power: " << en.CurrentPower() << "/" << en.MaxPower() << "\n";
	std::cout << "The Network is " << (!en ? "empty" : "not empty") << "\n";
	en - b - b;
	std::cout << "Devices: " << en.DevicesNumber() << " Power: " << en.CurrentPower() << "/" << en.MaxPower() << "\n";
	std::cout << "The Network is " << (!en ? "empty" : "not empty") << "\n";
	en + a;
	--en;
	--en;
	std::cout << "Devices: " << en.DevicesNumber() << " Power: " << en.CurrentPower() << "/" << en.MaxPower() << "\n";
	++en;
	en + b;
	std::cout << "Device " << en["ElectricVehicle"].getName() << " has power: " << en["ElectricVehicle"].getPower() << "\n";
	std::cout << "Device " << en["MegaPC"].getName() << " has power: " << en["MegaPC"].getPower() << "\n";
	std::cout << "The above row is empty because the item returned is invalid (not in the list - 0 pow).\n";
}
int main() 
{
	Test();
	return 0;
}
