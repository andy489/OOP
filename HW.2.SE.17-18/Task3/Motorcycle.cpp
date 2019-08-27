#include "Motorcycle.h"

Motorcycle::Motorcycle(string Make, string Model, string Color, 
	int Year, int Mileage, string Type) :
	Vehicle(Make, Model, Color, Year, Mileage), type(Type){}

void Motorcycle::setType(string Type)
{
}

string Motorcycle::getType() const
{
	return this->type;
}

void Motorcycle::details() const
{
	std::cout << "Make: " << make << "\n"
		<< "Model: " << model << "\n"
		<< "Color: " << color << "\n"
		<< "Year: " << year << "\n"
		<< "Mileage: " << mileage << "\n"
		<< "Type: " << type << "\n";
}
