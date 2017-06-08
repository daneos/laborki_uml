#if !defined(__CIRCLE_H__)
#define __CIRCLE_H__

#include <stdlib.h>
#include <math.h>
#include "Shape.h"

class Circle : public Shape
{
protected:
	const float radius;
public:
	Circle(const float r);
	~Circle();

	bool isIn(const Point &p) const;
};

#endif /* __CIRCLE_H__ */