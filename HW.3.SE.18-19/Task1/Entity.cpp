#include "Entity.h"

Entity::Entity()
{
	Point3D p;
	setLocation(&p);
	/*We have two setLocation-s with 2D and 3D,
	so in that way we can set the location wathever the point is
	and for more functionality we have setLocation
	with pointer to 2D (which is the base class)*/

	static size_t id = 1;
	this->id = id++;
}

Entity::Entity(std::string name, Point2D location) : Entity()
{
	setName(name);
	setLocation(location);
}

Entity::Entity(std::string name, Point3D location) : Entity()
{
	setName(name);
	setLocation(location);
}

Entity::Entity(const Entity & e)
{
	this->type = e.getType();
	this->id = e.getId();
	setName(e.getName());
	setLocation(e.getLocation());
}

Entity::~Entity()
{
	delete this->location;
}

const size_t Entity::getId() const
{
	return this->id;
}

Point2D * Entity::getLocation() const
{
	return this->location;;
}

void Entity::setLocation(Point2D *loc)
{
	delete this->location;
	Point3D* point3D = dynamic_cast<Point3D*>(loc);
	if (point3D != 0) this->location = new Point3D(*point3D);	
	else this->location = new Point2D(*loc);	
}

void Entity::setLocation(Point2D loc)
{
	setLocation(&loc);
}

void Entity::setLocation(Point3D loc)
{
	setLocation(&loc);
}

const std::string Entity::getName() const
{
	return name;
}

void Entity::setName(std::string name)
{
	this->name = name;
}

EntityType Entity::getType() const
{
	return this->type;
}

void Entity::setType(const EntityType type)
{
	this->type = type;
}

bool Entity::isAlive() const
{
	return true;
}

const double Entity::getDistanceTo2D(const Entity & e) const
{
	Point2D *castTo2D = dynamic_cast<Point2D*>(e.getLocation());
	double distance = getLocation()->getDistanceTo(*castTo2D);
	return distance;
}

const double Entity::getDistanceTo(const Entity & e) const
{
	Point3D *thisCastTo3D = dynamic_cast<Point3D*>(getLocation());
	Point3D *castTo3D = dynamic_cast<Point3D*>(e.getLocation());

	double distance;

	if (thisCastTo3D != nullptr && castTo3D != nullptr)
	{
		distance = thisCastTo3D->getDistanceTo(*castTo3D);
	}
	else
	{
		distance = getLocation()->getDistanceTo(*(e.getLocation()));
	}
	return distance;
}

void Entity::moveTo(Point2D *ptr)
{
	Point3D *thisCastTo3D = dynamic_cast<Point3D*>(getLocation());
	Point3D *castTo3D = dynamic_cast<Point3D*>(ptr);

	if (thisCastTo3D != nullptr && castTo3D != nullptr)
	{
		setLocation(ptr);
	}
	else
	{
		(*this->location).setX(ptr->getX());
		this->location->setY(ptr->getY());
	}
}

void Entity::moveTo(Entity &entity)
{
	Point3D *thisCastTo3D = dynamic_cast<Point3D*>(getLocation());
	Point3D *castTo3D = dynamic_cast<Point3D*>(entity.getLocation());
	if (thisCastTo3D != nullptr && castTo3D != nullptr)
	{
		setLocation(entity.getLocation());
	}
	else
	{
		location->setX(entity.location->getX());
		location->setY(entity.location->getY());
	}
}

void Entity::print() const
{
	std::cout << "ID: " << getId() << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Type: " << getType() << std::endl;
	getLocation()->print();
}
