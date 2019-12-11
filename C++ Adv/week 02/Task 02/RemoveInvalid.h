#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include "Company.h"

#include <list>

void removeInvalid(std::list<Company*>& companies) {
	auto i = companies.begin();

	while (i != companies.end()) {
		Company* c = *i;
		if (c->getId() < 0) {
			delete c;
			i = companies.erase(i);
		}
		else {
			i++;
		}
	}
}

#endif // !REMOVE_INVALID_H

