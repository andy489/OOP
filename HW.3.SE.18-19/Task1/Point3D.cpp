#include "Point3D.h"

Point3D::Point3D() :Point2D()
{
	setZ(0);
}

Point3D::Point3D(const double x, const double y, const double z) : Point2D(x, y), z(z)
{}

Point3D::~Point3D()
{
	/* Destroying obj of type Point3D - first destroying x and y 
	from the destructor of 2D and after that z */
}

const double Point3D::getZ() const
{
	return this->z;
}

void Point3D::setZ(const double z)
{
	this->z = z;
}

Point3D::Point3D(const Point3D & p) :Point2D(p)
{
	setZ(p.getZ());
}

const double Point3D::getDistanceTo(const Point3D & p)
{
	double distance;
	distance = mySqrt(myPower(getX() - p.getX(), 2) +
		myPower(getY() - p.getY(), 2) +
		myPower(getZ() - p.getZ(), 2));
	return distance;
}

void Point3D::print() const
{
	std::cout << "Location: " << getX() << ' ' << getY() << ' ' << getZ() << std::endl;
}
