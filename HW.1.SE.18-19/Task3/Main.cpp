#include "Store.h"

int main()
{
	// functionality:
	std::cout << "Functionality:\nA\tAdd new product\nX\tDelete product\nC\tChange product\nD\tDisplay products\nQ\tQuit\n\n";
	Store s;

	s.addProduct({ "Nokia", "3310", 50.50, 12 });
	s.addProduct({ "iPhone", "8", 950.50, 50 });
	s.addProduct({ "Samsung", "galaxy", 850.50, 15 });
	s.addProduct({ "iPhone", "6 Plus", 430.50, 3 });

	while (1)
	{
		char command;
		std::cin >> command;
		if (command == 'Q')	break;
		switch (command)
		{
		case 'A':
		{
			std::cout << "Add product: " << std::endl;

			char* brand = new char[32];
			std::cout << "brand: ";
			std::cin.ignore();
			std::cin.getline(brand, 32);

			char* model = new char[32];
			std::cout << "model: ";
			std::cin.ignore();
			std::cin.getline(model, 32);

			float price;
			std::cout << "price: ";
			std::cin >> price;
			std::cin.ignore();

			unsigned int count;
			std::cout << "count: ";
			std::cin >> count;
			std::cin.ignore();

			Product p(brand, model, price, count);
			s.addProduct(p);
			std::cout << "New product added\n";
			break;
		}
		case 'X':
		{
			std::cout << "Remove product at index: ";

			size_t index;
			std::cin >> index;
			bool isRemoved = s.removeProduct(index);
			if (isRemoved) std::cout << "Product at index " << index << " removed." << std::endl;
			else std::cout << "You did't removed anything. Index out of range." << std::endl;
			break;
		}
		case 'C':
		{
			unsigned int index;
			std::cout << "Which product do you want to change?\n";
			std::cin >> index;
			std::cin.ignore();

			char* brand = new char[32];
			std::cout << "brand: ";
			std::cin.getline(brand, 32);

			char* model = new char[32];
			std::cout << "model:";
			std::cin.getline(model, 32);

			float price;
			std::cout << "price:";
			std::cin >> price;
			std::cin.ignore();

			unsigned int count;
			std::cout << "count:";
			std::cin >> count;
			std::cin.ignore();

			Product m(brand, model, price, count);

			s.changeProduct(index, m);
			delete[] brand;
			delete[] model;
			break;
		}
		case 'D':
		{
			std::cout << "Printing all products: " << std::endl;

			s.printStore();
			break;
		}
		case 'M':
		{
			std::cout << "Functionality:\nA\tAdd new product\nX\tDelete product\nC\tChange product\nD\tDisplay products\nQ\tQuit\n\n";
			break;
		}
		case ' ':
		case '\n':
			break;
		default:
			std::cout << "invalid command" << std::endl;
		}
	}
}
