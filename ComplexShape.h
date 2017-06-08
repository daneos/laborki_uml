#if !defined(__COMPLEXSHAPE_H__)
#define __COMPLEXSHAPE_H__

#include "Shape.h"
#include "Utils.h"

class ComplexShape : public Shape
{
protected:
	const Shape *left;
	const Shape *right;
	const Operation op;

public:
	ComplexShape(const Shape *left, const Shape *right, const Operation op);
	~ComplexShape();

	bool isIn(const Point &p) const;
	
};

#endif /* __COMPLEXSHAPE_H__ */