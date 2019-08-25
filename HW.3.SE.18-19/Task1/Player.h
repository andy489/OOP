#pragma once
#include "Killable.h"

class Player :public Killable
{
public:
	Player();
	Player(const char* name, Point2D loc, const int damage, const int health);
	Player(const char* name, Point3D loc, const int damage, const int health);

	Player(const Player& p);

	bool isAlive()const override;

	void attack(Killable *ptr) const override;

	void print()const override;
};
