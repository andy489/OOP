#pragma once
#include "Product.h"

class Store
{   //private by default
	Product** products=nullptr;
	size_t size = 0;
	size_t cap = 0;
  ~Store();
};
