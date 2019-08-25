#include "NPC.h"

NPC::NPC() :Entity()
{
	setType(ENTITY_NPC);
}

NPC::NPC(const char * name, Point2D loc) : Entity(name, loc)
{
	setType(ENTITY_NPC);
}

NPC::NPC(const char * name, Point3D loc) : Entity(name, loc)
{
	setType(ENTITY_NPC);
}

NPC::NPC(const NPC & n) : Entity(n){}

bool NPC::isAlive() const
{
	return true;
}

void NPC::print() const
{
	std::cout << "NPC:" << std::endl;
	Entity::print();
}
