#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vehicle 
{
protected:
	string make;
	string model;
	string color;
	int year;
	int mileage;
public:
	Vehicle(string Make = "", string Model = "", string Color = "", int Year = 0, int Mileage = 0);
	void setMake(string Make);
	void setModel(string Model);
	void setColor(string Color);
	void setYear(int Year);
	void setMileage(int Mileage);
	string getMake() const;
	string getModel() const;
	string getColor() const;
	int getYear() const;
	int getMileage() const;
	virtual void details() const = 0;
};
