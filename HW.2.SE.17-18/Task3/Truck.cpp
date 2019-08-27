#include "Truck.h"

Truck::Truck(string Make, string Model, string Color, 
	int Year, int Mileage, int Length) : 
	Vehicle(Make, Model, Color, Year, Mileage), size(Length){}

int Truck::getSize() const
{
	return size;
}

void Truck::setSize(int Meters)
{
	size = Meters;
}

void Truck::details() const
{
	std::cout << "Make: " << make << "\n"
		<< "Model: " << model << "\n"
		<< "Color: " << color << "\n"
		<< "Year: " << year << "\n"
		<< "Mileage: " << mileage << "\n"
		<< "Size in meters: " << size << "\n";
}
