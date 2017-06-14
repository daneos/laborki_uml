#if !defined(__COMPLEXSHAPE_H__)
#define __COMPLEXSHAPE_H__

#include <memory>
#include "Shape.h"
#include "Utils.h"

using namespace std;

class ComplexShape : public Shape
{
protected:
	const shared_ptr<Shape> left;
	const shared_ptr<Shape> right;
	const Operation op;

public:
	ComplexShape(const shared_ptr<Shape> left, const shared_ptr<Shape> right, const Operation op);
	~ComplexShape();

	bool isIn(const Point &p) const;
	
};

#endif /* __COMPLEXSHAPE_H__ */