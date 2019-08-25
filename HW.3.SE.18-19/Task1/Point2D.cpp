#include "Point2D.h"

Point2D::Point2D()
{
	setX(0);
	setY(0);
}

Point2D::Point2D(const double x, const double y)
{
	setX(x);
	setY(y);
}

Point2D::~Point2D()
{
	//Destroying obj of type Point2D (no dynamic memory used, so no implementation)
}

Point2D::Point2D(const Point2D & p)
{
	setX(p.getX());
	setY(p.getY());
}


const double Point2D::getX() const
{
	return this->x;
}

const double Point2D::getY() const
{
	return this->y;
}

void Point2D::setX(const double x)
{
	this->x = x;
}

void Point2D::setY(const double y)
{
	this->y = y;
}

const double Point2D::getDistanceTo(const Point2D & p) const
{
	double distance;
	distance = mySqrt(myPower(getX() - p.getX(), 2) + myPower(getY() - p.getY(), 2));
	return distance;
}

void Point2D::print() const
{
	std::cout << "Location: " << getX() << ' ' << getY() << std::endl;
}
//My power function using Keratsuba multiplication algorithm with recursion method.
double myPower(double a, size_t n)
{
	if (n == 0)		return 1;
	if (n == 1)		return a;
	if (n % 2 == 0)
	{
		double result = myPower(a, n / 2);
		return result * result;
	}
	else return a * myPower(a, n - 1);
}
//My absolute function using s simple ternary operator.
double myAbs(double a)
{
	return a < 0 ? -a : a;
}
//My sqrt root 2 function using the Babylonian method.
double mySqrt(double a)
{
	double eps = 0.0001;
	double s = a;
	while ((s - a / s) > eps) s = (s + a / s) / 2;
	return s;
}
