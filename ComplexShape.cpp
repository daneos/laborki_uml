#include "ComplexShape.h"

ComplexShape::ComplexShape(const Shape *left, const Shape *right, const Operation op) : left(left), right(right), op(op)
{
}

ComplexShape::~ComplexShape()
{
}

bool ComplexShape::isIn(const Point &p) const
{
	Point t = p.translate(this->pos);

	if(op == UNION)
		return left->isIn(t) || right->isIn(t);
	else if(op == DIFFERENCE)
		return left->isIn(t) && !right->isIn(t);
	else if(op == INTERSECTION)
		return left->isIn(t) && right->isIn(t);
	else if(op == SYMMETRIC_DIFF)
		return (left->isIn(t) || right->isIn(t)) && !(left->isIn(t) && right->isIn(t));
}