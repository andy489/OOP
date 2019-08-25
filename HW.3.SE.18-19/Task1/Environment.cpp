#include "Environment.h"

Environment::Environment() {}

const Environment & Environment::operator=(const Environment & env)
{
	return *this;
}

Environment::~Environment()
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}
}

Environment * Environment::getInstance()
{
	if (nullptr == environment)
	{
		environment = new Environment();
	}
	return environment;
}

void Environment::releaseInstance()
{
	if (nullptr != environment)
	{
		delete environment;
		environment = nullptr;
	}
}

void Environment::add(Entity* e)
{
	Player *player = dynamic_cast<Player*>(e);
	Mob *mob = dynamic_cast<Mob*>(e);
	NPC *npc = dynamic_cast<NPC*>(e);

	Entity* newEntity;

	if (player != 0) newEntity = new Player(*player);
	else if (mob != 0) newEntity = new Mob(*mob);
	else if (npc != 0) newEntity = new NPC(*npc);
	else throw std::invalid_argument("Invalid entity type");

	entities.push_back(newEntity);
}

const size_t Environment::getEntitiesCount() const
{
	return entities.size();
}

Entity * Environment::getAt(size_t index)
{
	return entities.at(index);
}

bool Environment::removeAt(size_t index)
{
	if (index < entities.size())
	{
		delete[] entities[index];
		entities.erase(entities.begin() + index);
		return true;
	}
	return false;
}

void Environment::generateEntities(const size_t count)
{
	const char* names[] = {
		"Hydra",
		"Zealot",
		"Dragoon",
		"Sorcerer",
		"Diablo",
		"Paladin",
		"Pit Lord"
	};

	for (size_t i = 0; i < count; i++)
	{
		size_t enumType = rand() % 3;
		size_t nameType = rand() % (sizeof(names) / sizeof(names[0]));

		Point2D* p;
		/* we randomise the points in order to create from both types 2D and 3D */
		if (rand() % 2)
		{   /* we limit the points by modulo 7 */			
			p = new Point2D(rand() % 7, rand() % 7);
		}
		else
		{   /* we limit the points by modulo 7 */
			p = new Point3D(rand() % 7, rand() % 7, rand() % 7);
		}

		Point2D p2d;

		switch (enumType)
		{
		case 0:
		{
			Player player(names[nameType], p2d, rand() % 8 + 5, 100);
			player.setLocation(p);
			this->add(&player);
			break;
		}
		case 1:
		{
			Mob mob(names[nameType], p2d, rand() % 4 + 1, 80);
			mob.setLocation(p);
			this->add(&mob);
			break;
		}
		case 2:
		{
			NPC npc(names[nameType], p2d);
			npc.setLocation(p);
			this->add(&npc);
			break;
		}
		}
		delete p;
	}
}

void Environment::destroyEntities()
{
	while (entities.size() > 0)
	{
		delete entities.back();
		entities.pop_back();
	}
}

Entity * Environment::getClosestAliveEntity(const Player & player, EntityType type)
{
	if (entities.size() == 0) return 0;

	Entity *minEntity = nullptr;
	double minDistance = std::numeric_limits<double>::max();

	for (size_t i = 0; i < entities.size(); i++)
	{
		{
			if (entities[i]->isAlive() && entities[i]->getType() == type && entities[i]->getId() != player.getId())
			{
				double d = player.getDistanceTo(*entities[i]);
				if (d < minDistance)
				{
					minEntity = entities[i];
					minDistance = d;
				}
			}
		}
	}
	return minEntity;

}
void Environment::print() const
{
	for (std::vector<Entity*>::const_iterator it = entities.begin(); it != entities.end(); ++it)
	{
		(*it)->print();
		std::cout << std::endl;
	}
}
