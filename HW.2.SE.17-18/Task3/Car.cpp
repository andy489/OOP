#include "Car.h"

Car::Car(string Make, string Model, string Color, int Year, int Mileage) : 
	Vehicle(Make, Model, Color, Year, Mileage) {}

void Car::details() const
{
	std::cout << "Make: " << make << "\n"
		<< "Model: " << model << "\n"
		<< "Color: " << color << "\n"
		<< "Year: " << year << "\n"
		<< "Mileage: " << mileage << "\n";
}
