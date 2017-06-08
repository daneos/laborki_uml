#if !defined(__SHAPE_H__)
#define __SHAPE_H__

#include "Point.h"

class Shape
{
protected:
	Point pos;

public:
	Shape();
	~Shape();
	
	virtual bool isIn(const Point &p) const = 0;
	void setPosition(const Point &p);
};

#endif /* __SHAPE_H__ */