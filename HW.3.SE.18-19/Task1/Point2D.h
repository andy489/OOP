#pragma once
#include <iostream>
#include <string>

class Point2D
{
	double x;
	double y;
public:
	Point2D();
	Point2D(const double x, const double y);

	Point2D(const Point2D& p);

	const double getX()const;
	const double getY() const;

	void setX(const double x);
	void setY(const double y);

	const double getDistanceTo(const Point2D& p) const;

	virtual void print() const;

	virtual ~Point2D();
};

double myPower(double a, size_t n);
double myAbs(double a);
double mySqrt(double a);
