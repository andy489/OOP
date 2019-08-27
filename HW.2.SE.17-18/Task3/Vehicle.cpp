#include "Vehicle.h"

Vehicle::Vehicle(string Make, string Model, string Color, int Year, int Mileage) :
	make(Make), model(Model), color(Color), year(Year), mileage(Mileage) {}

void Vehicle::setMake(string Make)
{
	make = Make;
}

void Vehicle::setModel(string Model)
{
	model = Model;
}

void Vehicle::setColor(string Color)
{
	color = Color;
}

void Vehicle::setYear(int Year)
{
	year = Year;
}

void Vehicle::setMileage(int Mileage)
{
	mileage = Mileage;
}

string Vehicle::getMake() const
{
	return make;
}

string Vehicle::getModel() const
{
	return model;
}

string Vehicle::getColor() const
{
	return color;
}

int Vehicle::getYear() const
{
	return year;
}

int Vehicle::getMileage() const
{
	return mileage;
}


