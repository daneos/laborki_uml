#include "Rect.h"

Rect::Rect(const float w, const float h) : width(w), height(h)
{
}

Rect::~Rect()
{
}

bool Rect::isIn(const Point &p) const
{
	Point t = p.translate(this->pos);
	return ((abs(t.getX()) < width/2) && (abs(t.getY()) < height/2));
}