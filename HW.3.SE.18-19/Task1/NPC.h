#pragma once
#include "Entity.h"

class NPC :public Entity
{
public:
	NPC();
	NPC(const char* name, Point2D loc);
	NPC(const char* name, Point3D loc);

	NPC(const NPC& n);

	bool isAlive()const override;

	void print()const override;
};
