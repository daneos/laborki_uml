#include "Shape.h"

Shape::Shape() : pos(0, 0)
{
}

Shape::~Shape()
{
}

void Shape::setPosition(const Point &p)
{
	pos = p;
}