#include "Circle.h"

Circle::Circle(const float r) : radius(r)
{
}

Circle::~Circle()
{
}

bool Circle::isIn(const Point &p) const
{
	Point t = p.relativeTo(this->pos);
	return pow(t.getX(), 2) + pow(t.getY(), 2) <= pow(radius, 2);
}