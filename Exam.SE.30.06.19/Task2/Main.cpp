#include "Restaurant.h"

void test()
{
	Restaurant Victoria;

	Food f1(8, 16.90, "Fish Tacos", 300);
	Food f2(10, 12.90, "Greek Salad", 400);
	Drink d1(120, 4.40, "Corona Extra", 5.5);
	Drink d2(40, 10.90, "Mojito", 8.2);
	Drink d3(33, 15.80, "Whiskey Sour", 32.5);
	Drink d4(90, 2.50, "Apple Juice", 0);

	RestaurantItem* ptr1 = &f1;
	RestaurantItem* ptr2 = &f2;
	RestaurantItem* ptr3 = &d1;
	RestaurantItem* ptr4 = &d2;
	RestaurantItem* ptr5 = &d3;
	RestaurantItem* ptr6 = &d4;

	Victoria.addItem(ptr1);
	Victoria.addItem(ptr2);
	Victoria.addItem(ptr3);
	Victoria.addItem(ptr4);
	Victoria.addItem(ptr5);
	Victoria.addItem(ptr6);

	Victoria.printAllProducts();

	std::cout << "~Removing products:\n\n";
	for (unsigned i = 0; i < 2; i++)Victoria.eraseItem(0);

	Victoria.printAllProducts();

	std::cout << "~Displaying all non-alcohol drinks:\n\n";

	Victoria.printAllNonAlcDrinks();
}

int main()
{
	test();
	return 0;
}
