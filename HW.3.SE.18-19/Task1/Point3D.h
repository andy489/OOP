#pragma once
#include "Point2D.h"

class Point3D :public Point2D
{
	double z;
public:
	Point3D();
	Point3D(const double x, const double y, const double z);

	Point3D(const Point3D& p);

	const double getZ()const;

	void setZ(const double z);

	const double getDistanceTo(const Point3D &p);

	virtual void print() const override;

	virtual ~Point3D();
};
