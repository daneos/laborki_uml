#include "Point.h"

Point::Point(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

Point::~Point()
{
}

float Point::getX() const
{
	return x;
}

float Point::getY() const
{
	return y;
}

void Point::setX(const float x)
{
	this->x = x;
}

void Point::setY(const float y)
{
	this->y = y;
}

Point Point::translate(const Point &p) const
{
	Point t(this->getX() - p.getX(), this->getY() - p.getY());
	return t;

}