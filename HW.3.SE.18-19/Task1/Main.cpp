#include "Player.h"
#include "Mob.h"
#include "NPC.h"
#include "Environment.h"
#include <time.h>

/*
For clarity:
- Players are with health 100
- Mobs are with health 80
- The Barbarian is "our" player which is only one, and will be used to attack the Mobs,
it has damage 16, so when he attacks a Mob - it will left them with health 80-16=64,
if the distance between them is less than 5;
The Barbarian is also set to be with location (0,0,0),
so when he meets a Mob with 2D location,
his location transforms in 2D also (as wanted),
after that checks the distance and if is near enough attacks.
*/

void attackAllMobs(Environment& env, const Player& player)
{
	//We make a container of all the Mobs in the Environment:
	std::vector<Entity*> mobs;
	for (size_t i = 0; i < env.getEntitiesCount(); i++)
	{
		Entity* mob = env.getAt(i);
		if (mob->getType() == ENTITY_MOB && mob->isAlive())
		{
			mobs.push_back(mob);
		}
	}
	/*After that we sort the container with all the Mobs,
	starting with the closest to the player:*/
	while (1)
	{
		bool swapped = false;
		for (size_t i = 1; i < mobs.size(); i++)
		{
			double dis1 = player.getDistanceTo(*mobs[i - 1]);
			double dis2 = player.getDistanceTo(*mobs[i]);
			if (dis1 > dis2)
			{
				Entity* tempMob = mobs[i - 1];
				mobs[i - 1] = mobs[i];
				mobs[i] = tempMob;
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
	/*We attack all the Mobs in the container with the Mobs.
	They are sorted so the attack will begin with the closest Mob, as wanted*/
	for (size_t i = 0; i < mobs.size(); i++)
	{
		player.attack(dynamic_cast<Killable*>(mobs[i]));
	}
	/*The player will make damage to the Mob
	only if the distance between them is less than 5, as wanted*/
}

Environment* Environment::environment = nullptr;

int main()
{
	srand((size_t)time(0));

	Environment::getInstance()->generateEntities(8);

	Player p1("Barbarian", { 0,0,0 }, 16, 100);
	Environment::getInstance()->add(&p1);

	Environment::getInstance()->print();

	Entity* entity = Environment::getInstance()->getClosestAliveEntity(p1, ENTITY_MOB);

	std::cout << "--------------------------------------------------------------\n;";
	std::cout << "THE CLOSEST ALIVE MOB TO PLAYER \"BARBARIAN\":\n~if this mob is not attacked\n";
	std::cout << "(with less than 80 health, after calling \"attackAllMobs\"),\n";
	std::cout << "then none of the mobs will be attacked~\n*this check we make easy,";
	std::cout << "becaouse all entities have an unique id*\n";
	std::cout << "--------------------------------------------------------------\n";
	if (entity)
	{
		entity->print();
	}
	std::cout << "--------------------------------------------------------------\n";

	std::cout << "ATTACKING ALL MOBS WITH DISTANCE LESS THAN 5 TO THE BARBARIAN:\n";
	std::cout << "~if the distance is less than 5 the mob will be attacked~\n";
	std::cout << "--------------------------------------------------------------\n";

	attackAllMobs((*Environment::getInstance()), p1);
	Environment::getInstance()->print();

	Environment::releaseInstance();
	
	return 0;
}
