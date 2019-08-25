#pragma once
#include "Point3D.h"

enum EntityType 
{
	ENTITY_PLAYER,
	ENTITY_NPC,
	ENTITY_MOB
};

class Entity
{
	size_t id;
	std::string name;
	Point2D* location = nullptr;
	EntityType type;

protected:
	void setType(const EntityType type);

public:
	Entity();
	Entity(std::string name, Point2D location);
	Entity(std::string name, Point3D location);
	Entity(const Entity& e);

	const std::string getName()const;
	void setName(std::string name);

	const size_t getId() const;

	EntityType getType() const;

	void setLocation(Point2D *loc);
	void setLocation(Point2D loc);
	void setLocation(Point3D loc);

	Point2D* getLocation() const;

	virtual bool isAlive() const = 0;

	const double getDistanceTo2D(const Entity& e) const;
	const double getDistanceTo(const Entity& e)const;

	void moveTo(Point2D * ptr);
	void moveTo(Entity & entity);

	virtual void print()const;

	~Entity();
};
