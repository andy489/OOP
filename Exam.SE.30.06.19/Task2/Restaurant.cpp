#include "Restaurant.h"

Restaurant::Restaurant() {}

Restaurant::Restaurant(const Restaurant& r)
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		this->items[i] = r.items[i]->clone();
	}
}

Restaurant & Restaurant::operator=(const Restaurant & r)
{
	if (this != &r)
	{
		for (size_t i = 0; i < r.items.size(); i++)
		{
			delete r.items[i];
		}

		items.clear();

		for (unsigned i = 0; i < r.items.size(); i++)
		{
			items.push_back(r.items[i]->clone());
		}
	}
	return *this;
}

Restaurant::~Restaurant()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();
}

void Restaurant::addItem(RestaurantItem* item)
{
	/* We will implement this function not using the clone() function, but
	using dynamic cast, just to show the other way */
	Food* f = dynamic_cast<Food*>(item);
	Drink* d = dynamic_cast<Drink*>(item);

	RestaurantItem* newItem;

	if (f != 0)	newItem = new Food(*f);
	else if (d != 0) newItem = new Drink(*d);
	else throw std::invalid_argument("Invalid item type");
	items.push_back(newItem);

	//using clone() function
	//items.push_back(item->clone());
}

bool Restaurant::eraseItem(const unsigned index)
{
	if (index < items.size() && index >= 0)
	{
		delete items[index];
		items.erase(items.begin() + index);
		
		return true;
	}
	return false;
}

void Restaurant::printAllProducts() const
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		items[i]->print();
	}
}

void Restaurant::printAllNonAlcDrinks() const
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		Drink* d = dynamic_cast<Drink*>(items[i]); // dynamic cast
		if (d != nullptr && d->getAlc() == 0)
		{
			items[i]->print();
		}
	}
	/*for (unsigned i = 0; i < items.size(); i++)
	{
		if (items[i]->getType == DRINK)
		{
			Drink* d = (Drink*)items[i]; // static cast
			if (d->getAlc() == 0)
			{
				items[i]->print();
			}
		}
	}*/
}
