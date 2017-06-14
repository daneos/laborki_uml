#include <stdio.h>
#include "ComplexShape.h"
#include "Circle.h"
#include "Rect.h"
#include "Point.h"

void draw(const Shape &s, const Point &start, const Point &end, const int resX, const int resY)
{
	float diffX = (end.getX() - start.getX()) / resX;
	float diffY = (end.getY() - start.getY()) / resY;
	printf("diff = %f;%f\n\n", diffX, diffY);

	printf("-----------------------------------------------------------------------\n");
	for(float y = start.getY(); y >= end.getY(); y += diffY)
	{
		for(float x = start.getX(); x <= end.getX(); x += diffX)
		{
			Point p(x, y);
			if(s.isIn(p))
				printf("X");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("-----------------------------------------------------------------------\n");
}

int main(int argc, char *argv[])
{
	printf("main: arrived\n");

	auto sun = make_shared<Circle>(3);
	auto main_box = make_shared<Rect>(10, 10);
	auto small = make_shared<Rect>(14, 1);
	auto hole1 = make_shared<Rect>(3, 4);
	auto hole2 = make_shared<Circle>(1.5);

	auto hole = make_shared<ComplexShape>(hole1, hole2, UNION);
	auto main_layout = make_shared<ComplexShape>(main_box, small, UNION);
	auto full_shape = make_shared<ComplexShape>(main_layout, hole, DIFFERENCE);
	ComplexShape scene(full_shape, sun, UNION);

	small->setPosition(Point(0, 3));
	hole2->setPosition(Point(0, 2));
	hole->setPosition(Point(0, -3));
	full_shape->setPosition(Point(-2, 0));
	sun->setPosition(Point(10, 5));

	Point start(-10, 5);
	Point end(10, -5);

	draw(scene, start, end, 60, 40);

	return 0;
}