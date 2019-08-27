#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"

void Test()
{
	Motorcycle m1 = Motorcycle("Honda", "18k", "Black", 2005, 0, "Raver");
	Car c1 = Car("Ferrari", "4x4", "Red", 2018, 250);
	Truck t1 = Truck("Mercedes", "b30", "Colorful", 1998, 250000, 7);

	t1.setMileage(100000);

	Vehicle* ve[3];
	ve[0] = &m1;
	ve[1] = &c1;
	ve[2] = &t1;

	for (int i = 0; i < 3; i++)
	{
		ve[i]->details();
		std::cout << "\n";
	}
}

int main() 
{
	Test();
	return 0;
}
