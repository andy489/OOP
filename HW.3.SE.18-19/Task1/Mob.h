#pragma once
#include "Killable.h"

class Mob :public Killable
{
public:
	Mob();
	Mob(const char* name, Point2D loc, const int damage, const int health);
	Mob(const char* name, Point3D loc, const int damage, const int health);

	Mob(const Mob& m);

	bool isAlive()const override;

	void attack(Killable *ptr)const override;

	void print()const override;
};
