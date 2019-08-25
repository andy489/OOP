#pragma once
#include "Player.h"
#include "NPC.h"
#include "Mob.h"
#include <vector>
/* This class is Singleton in order to have only one instance "environment" */
class Environment
{
private:
	static Environment* environment;

	std::vector<Entity*>entities;

	Environment();
	Environment(const Environment & env); /* disallow copy constructor */
	const Environment &operator=(const Environment &env); /* disallow assignment operator */
	~Environment();

public:
	static Environment* getInstance();
	static void releaseInstance();

	void add(Entity* e);

	const size_t getEntitiesCount()const;

	Entity* getAt(size_t index);

	bool removeAt(size_t index);

	void generateEntities(const size_t count);

	void destroyEntities();

	Entity* getClosestAliveEntity(const Player& player, EntityType type);

	void print() const;
};
